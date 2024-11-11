#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
#include<algorithm>
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
using namespace std;
char s[200010];
int n, c[200010], a[200010];
long long ans;
vector < int > p[26];
bool check() {
	int cnt = 0;
	for (int i = 0; i < 26; ++i)
		cnt += p[i].size() & 1;
	return cnt < 2;
}
void add(int p, int x) {
	for (; p <= n; p += lowbit(p)) c[p] += x;
}
int sum(int p) {
	int res = 0;
	for (; p; p -= lowbit(p)) res += c[p];
	return res;
}
int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; ++i) p[s[i]-'a'].pb(i);
	if (!check()) return puts("-1"), 0;
	for (int i, sz, x = 0; x < 26; ++x) {
		for (i = 0; i < (sz = p[x].size()); ++i)
			a[p[x][i]] = p[x][sz-1-i];
	}
	for (int i = 1; i <= n; ++i)
		ans += sum(a[i]), add(a[i], 1);
	printf("%lld\n", ans / 2);
	return 0;	
}
