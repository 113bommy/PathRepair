#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;

int N;
int boss[7],height[7];

int get_boss(int id){
	if(boss[id] == id)return id;
	else{
		return boss[id] = get_boss(boss[id]);
	}
}

void unite(int x,int y){
	int boss_x = get_boss(x);
	int boss_y = get_boss(y);

	if(boss_x == boss_y)return;

	if(height[x] > height[y]){

		boss[boss_y] = boss_x;

	}else if(height[x] < height[y]){

		boss[boss_x] = boss_y;

	}else{ //height[x] == height[y]

		boss[boss_y] = boss_x;
		height[x]++;
	}
}

void init(){
	for(int i = 0; i < 7; i++){
		boss[i] = i;
		height[i] = 0;
	}
}

int main(){

	int array[7],num,num_KI,num_boss;

	char buf[3];
	int a,b;

	bool FLG;

	while(scanf("%d",&N) != EOF){

		init();
		for(int i = 0; i < 7; i++)array[i] = 0;

		for(int i = 0; i < N; i++){
			scanf("%s",buf);
			a = buf[0] - '0';
			b = buf[1] - '0';
			array[a]++;
			array[b]++;
			unite(a,b);
		}
		FLG = true;

		num_KI = 0;

		for(int i = 0; i < 7; i++)if(array[i]%2 == 1)num_KI++;

		if(num_KI > 2){
			printf("No\n");
			continue;
		}

		num_boss = 0;
		for(int i = 0; i < 7; i++){
			if(array[i] > 0 && i == get_boss(i))num_boss++;
		}
		if(num_boss > 1)FLG = false;

		if(FLG){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}

	return 0;
}