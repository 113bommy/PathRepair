#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
int N,K;
ll A[100010] = {0},S[100010] = {0},T[100010] = {0};

int main(){
	cin >> N >> K;
	for(int i=1;i<=N;i++){
		cin >> A[i];
		S[i] = S[i-1] + A[i];
		T[i] = T[i-1] + max(A[i]-A[i],A[i]);
	}
	ll ans = 0;
	for(int i=1;i<=N-K+1;i++){
		ans = max(ans,max(T[i-1] + S[i+K-1]-S[i-1] + T[N]-T[i+K-1],
			T[i-1] + T[N]-T[i+K-1]));
	}
	cout << ans << endl;
}