#include <bits/stdc++.h>
using namespace std;
int main(){
	int N, K;
	string S;
	cin >> N >> S >> K;
	sk = S[K];
	for(int i = 0; i < N; i++){
		if(S[i] != sk)
			S[i] = '*';
	}
	cout << S << endl;
}