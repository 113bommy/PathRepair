#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 1e5 + 5;
int N, M;
vector<pii> neigh[MAXN];
bool tk[MAXN];
int val[MAXN];

bool Fill(int v, int col) {
	if (tk[v]) return val[v] == col;
	tk[v] = true;
	val[v] = col;
	for (int i = 0; i < neigh[v].size(); i++) {
		pii u = neigh[v][i];
		if (!Fill(u.first, val[v] + u.second)) return false;
	}
	return true;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		neigh[a].push_back(pii(b, c));
		neigh[b].push_back(pii(a, -c));
	}
	for (int i = 1; i <= n; i++) {
		if (!tk[i]) {
			if (!Fill(i, 0)) {
				printf("No\n");
				return 0;
			}
		}
	}
	printf("Yes\n");
	return 0;
}