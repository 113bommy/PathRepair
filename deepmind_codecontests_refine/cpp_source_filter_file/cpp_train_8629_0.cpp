#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;

ll n, A[4001], memo[2001][2001] = {} ans = 0;
bool calced[2001][2001][2];
ll solve(int s, int e, bool JOI){
	if(memo[s][e]) return memo[s][e];
	if(s == e){
		if(JOI){
			return memo[s][e]=A[s];
		} else{
			return memo[s][e]=0;
		}
	}
	
	if(JOI){
		return memo[s][e]=max(solve(s + 1, e, 0) + A[s], solve(s,  e - 1, 0) + A[e]);
	} else{
		if(A[s] > A[e]){
			return memo[s][e]=solve(s + 1, e, 1);
		} else{
			return memo[s][e]=solve(s, e - 1, 1);
		}
	}
}

int main() {
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> A[i];
		A[i + n] = A[i];
	}
	
	for(int i = 0; i < n; i++){
		ans = max(ans, solve(i, i + n - 1, 1));
	}
	
	cout << ans << endl;
	
	return 0;
}