#include <bits/stdc++.h>
#define LL long long

const int N = 200101;
int n, cnt = 1, ch[N][2], len[N];
LL L;
bool num[111];
char s[200001];

int lowbit(LL x)
{
    int r = 0;
    for(;!(x & 1); r++, x >>= 1);
    return r;
}

void ins(int u, int id, int d, int leng) {
	if (ch[u][s[len[id] + d - 1] - '0'] == 0) {
		ch[u][s[len[id] + d - 1] - '0'] = ++ cnt;
	}
	if (d != leng) ins(ch[u][s[len[id] + d - 1] - '0'], id, d + 1, leng);
}

void dfs(int u, int d) {
	for (int k = 0; k <= 1; ++ k) {
		if (ch[u][k] == 0) {
			if (L - d > 0) num[lowbit(L - d)] ^= 1;
		} else dfs(ch[u][k], d + 1);
	}
}

int main() {
	std::cin >> n >> L;
	int tot = 0;
	for (int i = 1; i <= n; ++i) {
		len[i] = tot + 1;
		std::cin >> (s + len[i]);
		tot += strlen(s + len[i]);
		ins(1, i, 1, strlen(s + len[i]));
	}
	dfs(1, 0);
	for (int i = 0; i <= 60; ++i) {
		if (num[i]) {
			std::cout << "Alice\n";
			return 0;
		}
	}
	std::cout << "Bob\n";
	return 0;
}