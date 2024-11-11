#include <bits/stdc++.h>
using namespace std;

int main() {
	string S;
	int K,N;
	cin >>N>>S>>K;
	for(int i = 0 ; i < N ; i++){
		if(S[i] != S[K-1]){
			S[i] = '*';
		}
	}
	cout << S << endl;
}