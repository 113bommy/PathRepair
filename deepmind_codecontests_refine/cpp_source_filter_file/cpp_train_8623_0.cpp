#include <cstdio>
#include <algorithm>
#include <queue>

const int INF = 0x1f1f1f1f;

const int N = 200000;

const int lgN = 20;

typedef int ST[lgN][N];

ST st[2];

int p[N];

int lg[N];

int inv[N];

int qi;
int q[N];

int n;

void build(int d) {
	for (int x = 0; (1 << x) <= n; x++) {
		int y = 1 << x;
		int h = y >> 1;
		for (int i = 0; i <= n - y; i++) {
			if (x == 0)
				st[d][x][i] = i % 2 == d ? p[i] : INF;
			else
				st[d][x][i] = std::min(st[d][x - 1][i], st[d][x - 1][i + h]);
		}
	}
}

int query(int l, int r) {
	int x = lg[r - l + 1];
	return std::min(st[l % 2][x][l], st[l % 2][x][r - (1 << x) + 1]);
}

void init() {
	for (int i = 0; (1 << i) + 1 <= n; i++)
		lg[1 << i] = i;
	for (int i = 2; i <= n; i++)
		lg[i] = lg[i] == 0 ? lg[i - 1] : lg[i];
}

struct pair {
	int l, r, val;
	friend operator < (const pair& a, const pair& b) {
		return a.val > b.val;
	}
};

pair make_pair(int l, int r) {
	return (pair){l, r, query(l, r)};
}

std::priority_queue<pair> pq;

void solve() {

	pq.push(make_pair(0, n - 1));

	while (!pq.empty()) {

		pair t = pq.top();
		pq.pop();

		q[qi++] = t.val;

		int i = inv[t.val];

		int j_ = query(i + 1, t.r);

		q[qi++] = j_;

		int j = inv[j_];

		if (t.l < i - 1) pq.push(make_pair(t.l, i - 1));
		if (i + 1 < j - 1) pq.push(make_pair(i + 1, j - 1));
		if (j + 1 < t.r) pq.push(make_pair(j + 1, t.r));

	}

}

int main(int argc, char *argv[]) {
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
		inv[p[i]] = i;
	}
		
	init();
	
	build(0);
	build(1);
	
	solve();
	
	for (int i = 0; i < qi; i++)
		printf("%d ", q[i]);
	putchar('\n');
	
	return 0;

}
