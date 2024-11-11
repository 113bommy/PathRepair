#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define NUM 7

enum Type{
	A,
	B,
};

struct Info{
	int low,high;
};

int N;
int POW_2[7],POW_10[7];
int MIN_LEN[2],MAX_LEN[2];
Info info[NUM];
ll dp[2][16];
map<int,bool> MAP[2];
ll num_list[2][NUM]; //長さ別の数字のリスト
int head_min[NUM],head_max[NUM]; //先頭[len]文字の最小・最大数(A用)
int tail_min[NUM],tail_max[NUM]; //末尾[len]文字の最小・最大長(B用)
int head_table[1000][4][4]; //head_table[common_part_len][先頭から切り出す桁数] = 数

vector<int> state_table[16];
vector<int> HEAD[NUM],TAIL[NUM];

int get_length(ll num){

	if(num == 0){
		return 1;
	}

	int ret = 0;

	while(num > 0){
		num /= 10;
		ret++;
	}

	return ret;
}

//numの先頭len文字の数字を作る
int substr_front(int num,int tmp_len,int cut_len){

	num /= POW_10[tmp_len-cut_len];
	return num;
}

//numの末尾len文字の数字を作る
int substr_tail(int num,int len){
	num %= POW_10[len];
	return num;
}

//数字を作る
void recursive(Type type,int index,int finish_index,int num){

	int tmp_length;

	if(index == finish_index+1){

		auto at = MAP[type].find(num);
		if(at != MAP[type].end())return; //登録済

		MAP[type][num] = true;
		tmp_length = get_length(num);
		MAX_LEN[type] = max(MAX_LEN[type],tmp_length);
		MIN_LEN[type] = min(MIN_LEN[type],tmp_length);
		num_list[type][tmp_length] += 1;

		int tmp;

		if(type == A){

			for(int i = 1; i <= tmp_length; i++){
				tmp = substr_front(num,tmp_length,i);
				HEAD[i].push_back(tmp);
			}

		}else{

			for(int i = 1; i <= tmp_length; i++){
				tmp = substr_tail(num,i);
				TAIL[i].push_back(tmp);
			}
		}
		return;
	}

	int tmp_num,tmp_len,next_num;
	//次の数字を全探索する
	for(int i = info[index].low; i <= info[index].high; i++){
		tmp_len = get_length(i);
		next_num = num*POW_10[tmp_len]+i;
		recursive(type,index+1,finish_index,next_num);
	}
}

void init_dp(){

	for(int i = 0; i < 16; i++){
		dp[A][i] = 0;
		dp[B][i] = 0;
	}
}

bool rangeCheck(int num_B){
	if(num_B >= MIN_LEN[B] && num_B <= MAX_LEN[B]){
		return true;
	}else{
		return false;
	}
}

void func(){

	MAP[A].clear();
	MAP[B].clear();

	for(int i = 1; i < NUM; i++){
		num_list[A][i] = 0;
		num_list[B][i] = 0;

		head_min[i] = BIG_NUM;
		tail_min[i] = BIG_NUM;

		head_max[i] = 0;
		tail_max[i] = 0;

		HEAD[i].clear();
		TAIL[i].clear();
	}

	for(int i = 0; i < N; i++){
		scanf("%d %d",&info[i].low,&info[i].high);
	}

	MIN_LEN[A] = BIG_NUM;
	MIN_LEN[B] = BIG_NUM;

	MAX_LEN[A] = -1;
	MAX_LEN[B] = -1;

	//前半・後半でグループを作り、あらかじめ数字を作っておく
	recursive(A,0,N/2-1,0);
	recursive(B,N/2,N-1,0);

	for(int i = 1; i <= 5; i++){
		sort(HEAD[i].begin(), HEAD[i].end());
		HEAD[i].erase(unique(HEAD[i].begin(),HEAD[i].end()),HEAD[i].end());

		sort(TAIL[i].begin(),TAIL[i].end());
		TAIL[i].erase(unique(TAIL[i].begin(),TAIL[i].end()),TAIL[i].end());
	}

	int common_part_len; //中央部の長さ:0～3であるはず
	int common_max;

	ll ans = 0;

	bool is_First;
	int A_min,A_max,B_min,B_max;
	int tmp_A,tmp_B,add_A_len,add_B_len,part_num,tmp_num;
	int num_bit,a_len,b_len,tmp_state;

	bool FLG;

	for(int total_len = MIN_LEN[A]+MIN_LEN[B]; total_len <= MAX_LEN[A]+MAX_LEN[B]; total_len++){

		//中央部の長さと、中央部の数の上限を求める
		is_First = true;
		for(int a = MIN_LEN[A]; a <= min(MAX_LEN[A],total_len); a++){

			if(!rangeCheck(total_len-a))continue; //Bの長さが不適ならSKIP

			if(is_First){

				A_min = a;
				A_max = a;

				B_min = total_len-a;
				B_max = total_len-a;
				is_First = false;
			}else{
				A_max = a;
				B_min = total_len-a;
			}
		}

		common_part_len = A_max-A_min;

		if(common_part_len == 0){ //共通部の長さが0

			//包除原理の適用不要
			ll count_A = num_list[A][A_min];
			ll count_B = num_list[B][B_max];

			ans += count_A*count_B;

			continue;
		}

		//★共通部として考えられる、長さcommon_part_lenの数字を全探索★
		common_max = POW_10[common_part_len]-1;

		for(int common_num = 0; common_num <= common_max; common_num++){

			//★★★★共通の数字別に数え上げる★★★★
			init_dp();

			a_len = A_min;

			//Aの数字全探索
			for(int a = 0; a < HEAD[a_len].size(); a++){

				int tmp_A = HEAD[a_len][a];

				tmp_state = 0;

				for(int loop = 0; loop < common_part_len+1; loop++){

					//★common_numのうち、先頭common_part_len-loopがcommon_numにおけるAの専有部
					add_A_len = common_part_len-loop;

					if(add_A_len == 0){
						auto at = MAP[A].find(tmp_A);
						if(at == MAP[A].end()){ //tmp_Aが存在しない数字なら不可
							//Do nothing
						}else{
							tmp_state += POW_2[loop];
						}
						continue;
					}

					part_num = head_table[common_num][common_part_len][add_A_len];

					//先頭から現れるべき数字
					tmp_num = tmp_A*POW_10[add_A_len]+part_num;

					auto at = MAP[A].find(tmp_num);

					if(at == MAP[A].end()){ //条件を満たす数字がないので、今回のsateは計上しない
						//Do nothing
					}else{
						tmp_state += POW_2[loop];
					}
				}

				for(int i = 0; i < state_table[tmp_state].size(); i++){
					dp[A][state_table[tmp_state][i]] += 1;
				}
			}

			b_len = B_min;

			//Bの数字全探索
			for(int b = 0; b < TAIL[b_len].size(); b++){ //★★Bは左に数字を付け加えるので0スタート★★

				tmp_B = TAIL[b];

				tmp_state = 0;

				for(int loop = 0; loop < common_part_len+1; loop++){
					//★common_numのうち、末尾loopがcommon_numにおけるBの専有部

					add_B_len = loop;

					if(add_B_len == 0){
						if(tmp_B < POW_10[b_len-1]){ //先頭0は不可
							continue;
						}
						auto at = MAP[B].find(tmp_B);
						if(at == MAP[B].end()){ //作れない数字は不可
							//Do nothing
						}else{
							tmp_state += POW_2[loop];
						}
						continue;
					}

					part_num = substr_tail(common_num,add_B_len);

					if(part_num < POW_10[add_B_len-1]){ //★★先頭0は不可★★
						continue;
					}

					//Bとして現れるべき数字
					tmp_num = part_num*POW_10[b_len]+tmp_B;

					auto at = MAP[B].find(tmp_num);

					if(at == MAP[B].end()){ //条件を満たす数字がないので、今回のsateは計上しない
						//Do nothing
					}else{
						tmp_state += POW_2[loop];
					}
				}

				for(int i = 0; i < state_table[tmp_state].size(); i++){
					dp[B][state_table[tmp_state][i]] += 1;
				}
			}

			//★中央の数字ごとにdp集計<包除原理>★
			for(int state = 1; state < POW_2[common_part_len+1]; state++){

				num_bit = 0;

				for(int loop = 0; loop < common_part_len+1; loop++){
					if(state & (1 << loop)){
						num_bit++;
					}
				}

				if(num_bit%2 == 1){

					ans += dp[A][state]*dp[B][state];

				}else{

					ans -= dp[A][state]*dp[B][state];
				}
			}
		}
	}
	printf("%lld\n",ans);
}

//1～15の状態の、サブstateをあらかじめ求める関数
void make_state_table(){

	bool check[4];
	bool FLG;

	for(int state = 1; state < 16; state++){
		for(int loop = 0; loop < 4; loop++){
			if(state & (1 << loop)){
				check[loop] = true;
			}else{
				check[loop] = false;
			}
		}

		for(int add_state = 1; add_state < 16; add_state++){
			FLG = true;
			for(int loop = 0; loop < 4; loop++){
				if(add_state & (1 << loop)){
					if(!check[loop]){
						FLG = false;
						break;
					}
				}
			}
			if(FLG){
				state_table[state].push_back(add_state); //stateにおいて、add_stateがsub stateとして存在
			}
		}
	}
}

//0～999の数字の、先頭1～3桁の数の事前計算
void makeTable(){

	int work[3],tmp;
	stack<int> S;

	for(int num = 0; num <= 999; num++){ //数字

		tmp = num;

		for(int i = 2; i >= 0; i--){ //右詰めで数字を配置
			work[i] = tmp%10;
			tmp /= 10;
		}

		for(int common_part_len = 1; common_part_len <= 3; common_part_len++){ //全体の桁数
			for(int head_len = 1; head_len <= common_part_len; head_len++){
				tmp = 0;
				for(int k = 0; k < head_len; k++){
					tmp = 10*tmp+work[3-common_part_len+k];
				}
				head_table[num][common_part_len][head_len] = tmp;
			}
		}
	}
}

int main(){

	for(int i = 0; i < 7; i++){
		POW_2[i] = pow(2,i);
		POW_10[i] = pow(10,i);
	}

	makeTable();

	make_state_table();

	while(true){
		scanf("%d",&N);
		if(N == 0)break;

		func();
	}

	return 0;
}

