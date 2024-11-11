#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
#include <cmath>  
#include <complex>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <limits.h>  
#include <map>  
#include <math.h>  
#include <queue>  
#include <set>  
#include <stdlib.h>  
#include <string.h>  
#include <string>  
#include <time.h>  
#include <unordered_map>  
#include <unordered_set>  
#include <vector>  

#pragma warning(disable:4996)  
#pragma comment(linker, "/STACK:336777216")  
using namespace std;

#define mp make_pair  
#define Fi first  
#define Se second  
#define pb(x) push_back(x)  
#define szz(x) ((int)(x).size())  
#define rep(i, n) for(int i=0;i<n;i++)  
#define all(x) (x).begin(), (x).end()  
#define ldb ldouble  

typedef unsigned int uint;
typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

const int MX = 25005;
const int MM = 1000000007;

int A[MX];
int N, K, M;

pii operator+(pii l, pii r){ return pii((l.first + r.first) % MM, (l.second + r.second) % MM); }
pii operator*(ll K, pii r){ return pii(K*r.first % MM, K*r.second % MM); }

ll pw(ll a, ll b){
	ll r = 1;
	while(b){
		if(b&1) r = r*a % MM;
		a = a*a % MM; b /= 2;
	}
	return r;
}

int cnt[MX];
int check()
{
	int cur = 0;
	for(int i = 1; i <= K; i++){
		if(cnt[A[i]] == 0) cur++;
		cnt[A[i]] ++;
	}
	for(int i = K+1; i <= M; i++){
		if(cur == K) return 0;
		if(cnt[A[i]] == 0) cur++;
		cnt[A[i]]++;
		
		if(cnt[A[i-K]] == 1) cur--;
		cnt[A[i-K]]--;
	}
	for(int i = 1; i <= K; i++) cnt[i] = 0;
	for(int i = 1; i <= M; i++) cnt[A[i]] ++;
	for(int i = 1; i <= K; i++) if(cnt[i] >= 2) return 1;
	return 2;
}

ll pre[MX][405], suf[MX][405];
pii dp[2][MX][405] = {};

int main()
{
	scanf("%d%d%d", &N, &K, &M);
	for(int i = 1; i <= M; i++) scanf("%d", A+i);
	int type = check();
	if(type == 0){
		ll ans = (N-M+1) * pw(K, N-M) % MM;
		printf("%lld\n", ans);
		return 0;
	}
	if(type == 1){
		int P = 0, Q = 0;

		for(int i = 1; i <= K; i++) cnt[i] = 0;
		for(int i = 1; i <= M; i++){
			if(cnt[A[i]]){ P = i-1; break; }
			cnt[A[i]] ++;
		}
		for(int i = 1; i <= K; i++) cnt[i] = 0;
		for(int i = 1; i <= M; i++){
			if(cnt[A[M-i+1]]){ Q = i-1; break; }
			cnt[A[M-i+1]] ++;
		}

		pre[0][P] = 1;
		for(int i = 1; i <= N; i++){
			ll sum = 0;
			for(int j = K; j >= 1; j--){
				if(j == K) pre[i][j] = (K * pre[i-1][j] + pre[i-1][j-1]) % MM;
				else{
					sum = (sum + pre[i-1][j]) % MM;
					pre[i][j] = ((K-j+1) * pre[i-1][j-1] + sum) % MM;
				}
			}
		}
		suf[0][Q] = 1;
		for(int i = 1; i <= N; i++){
			ll sum = 0;
			for(int j = K; j >= 1; j--){
				if(j == K) suf[i][j] = (K * suf[i-1][j] + suf[i-1][j-1]) % MM;
				else{
					sum = (sum + suf[i-1][j]) % MM;
					suf[i][j] = ((K-j+1) * suf[i-1][j-1] + sum) % MM;
				}
			}
		}

		ll ans = 0;
		for(int i = 0; i <= N-M; i++){
			int l = i, r = N-M-i;
			ans = (ans + pre[l][K] * pw(K, r) + (pw(K, l) + MM - pre[l][K]) * suf[r][K]) % MM;
		}
		printf("%lld\n", ans);
	}
	else{
		auto assign = [](pii &x){ x = pii(x.first, (x.first + x.second) % MM); };
		dp[0][0][0] = pii(1, 0);
		for(int i = 1; i <= N; i++){
			pii s0 = pii(0, 0), s1 = pii(0, 0);
			for(int j = K; j >= 1; j--){
				s0 = s0 + dp[0][i-1][j];
				dp[0][i][j] = (K-j+1) * dp[0][i-1][j-1] + s0;
				s1 = s1 + dp[1][i-1][j];
				dp[1][i][j] = (K-j+1) * dp[1][i-1][j-1] + s1;
			}
			dp[1][i][K] = dp[0][i][K] + dp[1][i][K];
			dp[0][i][K] = pii(0, 0);
			for(int j = M; j <= K; j++) assign(dp[0][i][j]), assign(dp[1][i][j]);
		}
		ll ans = 0;
		for(int i = 0; i <= K; i++) ans = (ans + dp[1][N][i].second) % MM;
		for(int i = K-M+1; i <= K; i++) ans = ans * pw(i, MM-2) % MM;
		printf("%lld\n", ans);
	}
}
