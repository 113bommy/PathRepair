#include<bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e9;
const int inf = 1e18;
const int MOD = 1e9 + 7;

int f(int b, int n){
	if (n < b){
		return n;
	}
	return f(b, n / b) + (n % b);
}

int main(){
	int n, s, b;
	cin >> n >> s;
	if (n == s){
		cout << n + 1;
		return 0;
	}
	int ans = inf;
	for (int i = 2; i * i <= n; i++){
		if (f(i, n) == s){
			cout << i;
			return 0;
		}
	}
	for (int i = 1; i * i <= n - s; i++){
		b = (n - s) / i + 1;
		if (f(b, n) == s){
			ans = min(ans, b);
		}
	}
	if (ans == inf){
		cout << -1;
		return 0;
	}
	cout << ans;
}