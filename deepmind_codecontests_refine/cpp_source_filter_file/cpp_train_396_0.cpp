#include <iostream>
#include <string>
#define inf 1000000000

using namespace std;

string s;
int N;
int hash[200005];
int table[1<<26];
int dp[200005];

int main(void)
{
	cin >> s;
	N = s.size(); 
	s = " " + s;
	
	for(int i = 1; i <= N; i++){
		hash[i] = hash[i-1] ^ (1 << (s[i]-'a'));
	}
	for(int i = 1; i <= N; i++) dp[i] = inf;
	for(int i = 1; i < (1<<26); i++) table[i] = inf;
	
	for(int i = 1; i <= N; i++){
		for(int j = 0; j < 26; j++){
			dp[i] = min(dp[i], table[hash[i] ^ (1<<j)] + 1);
		}
		dp[i] = min(dp[i], table[hash[i]] + 1);
		table[hash[i]] = min(table[hash[i]], dp[i]);
	}
	
	cout << dp[N] << endl;
	return 0;
}