#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;

struct Cell{
	Cell(int arg_row,int arg_col){
		row = arg_row;
		col = arg_col;
	}
	bool operator<(const struct Cell &arg) const{
		if(row != arg.row){
			return row < arg.row;
		}else{
			return col < arg.col;
		}
	};
	int row,col;
};

struct Info{
	int discount,start,end;
};

struct Data{
	Data(int arg_row,int arg_col,int arg_total_dist){
		row = arg_row;
		col = arg_col;
		total_dist = arg_total_dist;
	}

	int row,col,total_dist;
};

struct SALE{
	SALE(){
		state = time = row = col = sum_discount = 0;
	}

	SALE(int arg_state,int arg_time,int arg_row,int arg_col,int arg_sum_discount){
		state = arg_state;
		time = arg_time;
		row = arg_row;
		col = arg_col;
		sum_discount = arg_sum_discount;
	}

	int state,time,row,col,sum_discount;
};

int W,H;
int POW[11];
int dp[1024][20][20];
Info info[10];
bool is_sale[10];
int diff_row[4] = {-1,0,0,1},diff_col[4] = {0,-1,1,0};

char base_map[20][21];

bool rangeCheck(int row,int col){
	if(row >= 0 && row <= H-1 && col >= 0 && col <= W-1)return true;
	else{
		return false;
	}
}



void func(){

	char buf[2];

	int start_row,start_col;

	for(int row = 0; row < H; row++){
		for(int col = 0; col < W; col++){
			scanf("%s",buf);
			base_map[row][col] = buf[0];
			if(buf[0] == 'P'){
				base_map[row][col] = '.';
				start_row = row;
				start_col = col;
			}
		}
	}

	int N;
	scanf("%d",&N);

	int g,d,s,e;

	for(int i = 0; i < 10; i++)is_sale[i] = false;

	for(int loop = 0; loop < N; loop++){
		scanf("%d %d %d %d",&g,&d,&s,&e);

		info[g].discount = d;
		info[g].start = s;
		info[g].end = e;

		is_sale[g] = true;
	}

	int limit = POW[10];

	for(int state = 0; state < limit; state++){
		for(int row = 0; row < H; row++){
			for(int col = 0; col < W; col++){
				//dp[state][row][col] = BIG_NUM; //????????????????????????
				dp[state][row][col] = -1;
			}
		}
	}

	queue<SALE> Q;

	dp[0][start_row][start_col] = 0;

	SALE first;
	first.row = start_row;
	first.col = start_col;
	first.state = 0;
	first.sum_discount = 0;
	first.time = 0;

	Q.push(first);
	int max_value = 0;

	while(!Q.empty()){

		//printf("row:%d col:%d time:%d sum:%d state:%d\n",Q.front().row,Q.front().col,Q.front().time,Q.front().sum_discount,Q.front().state);

		max_value = max(max_value,Q.front().sum_discount);

		for(int i = 0; i < 4; i++){
			int adj_row = Q.front().row + diff_row[i];
			int adj_col = Q.front().col + diff_col[i];

			if(rangeCheck(adj_row,adj_col) == false)continue;

			if(base_map[adj_row][adj_col] == '.'){ //???????????´???

				if(dp[Q.front().state][adj_row][adj_col] < Q.front().sum_discount){
					dp[Q.front().state][adj_row][adj_col] = Q.front().sum_discount;

					SALE next_sale;
					next_sale.row = adj_row;
					next_sale.col = adj_col;
					next_sale.state = Q.front().state;
					next_sale.sum_discount = Q.front().sum_discount;
					next_sale.time = Q.front().time+1;

					//printf("?????? row:%d col:%d?????????%d state:%d??§????§?\n",adj_row,adj_col,Q.front().time+1,Q.front().state);

					Q.push(next_sale);
				}
			}else if(base_map[adj_row][adj_col] >= '0' && base_map[adj_row][adj_col] <= '9'){

				int adj_item = base_map[adj_row][adj_col]-'0';

				if(Q.front().state & (1 << adj_item))continue;
				if(is_sale[adj_item] == false)continue;

				int next_state = Q.front().state + POW[adj_item];

				if(Q.front().time >= info[adj_item].start && Q.front().time < info[adj_item].end){ //??????????§??????????????????§?????????????????????

					if(dp[next_state][Q.front().row][Q.front().col] < Q.front().sum_discount+info[adj_item].discount){

						dp[next_state][Q.front().row][Q.front().col] = Q.front().sum_discount+info[adj_item].discount;

						SALE next_sale;
						next_sale.row = Q.front().row;
						next_sale.col = Q.front().col;
						next_sale.state = next_state;
						next_sale.sum_discount = Q.front().sum_discount+info[adj_item].discount;
						next_sale.time = Q.front().time;

						//printf("?????? row:%d col:%d?????????%d state:%d??§????§?\n",adj_row,adj_col,Q.front().time+1,Q.front().state);

						Q.push(next_sale);

					}

				}else if(Q.front().time < info[adj_item].start){

					/*if(dp[next_state][Q.front().row][Q.front().col] < Q.front().sum_discount+info[adj_item].discount){

						dp[next_state][Q.front().row][Q.front().col] = Q.front().sum_discount+info[adj_item].discount;*/
						SALE next_sale;
						next_sale.row = Q.front().row;
						next_sale.col = Q.front().col;
						next_sale.state = Q.front().state;
						next_sale.sum_discount = Q.front().sum_discount;
						next_sale.time = info[adj_item].start;

						//printf("?????\?????? row:%d col:%d?????????%d state:%d??§????§?\n",adj_row,adj_col,Q.front().time+1,Q.front().state);

						Q.push(next_sale);
					/*}
				}*/
			}
		}
		Q.pop();
	}

	printf("%d\n",max_value);
}


int main(){

	for(int i = 0; i <= 10; i++)POW[i] = pow(2,i);

	while(true){
		scanf("%d %d",&W,&H);
		if(W == 0 && H == 0)break;

		func();
	}

	return 0;
}