#include <bits/stdc++.h>
using namespace std;

int N;
long long A[100001], K;

int main(){
	long long cnt = 0;
	cin >> N >> K;
	for(int i = 0; i < N; i++){
		int a, b;
		cin >> a >> b;
		A[a] += b;
	}
	for(int i = 1; i < 100001; i++){
		cnt += A[i];
		if(cnt >= K){
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}
