#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <climits>
using namespace std;

long long bit[100010] = {};

void add(int x,long long v){
	for(int i = x ; i < 100010 ; i += i & -i ){
		bit[i] = max(bit[i],v);
	}
}

long long get(int x){
	long long ans = 0;
	for(int i = x ; i > 0 ; i -= i & -i ){
		ans = max(bit[i],ans);
	}
	return ans;
}

int main(){
	int n;
	cin >> n;
	long long ans = 0;
	for(int i = 0 ; i < n ; i++){
		int a;
		cin >> a;
		add(a,get(a)+a);
	}
	cout << 1ll*n*(n+1) / 2 - get(100001) << endl;
}