#include<iostream>
#include<string>
#include<cmath>
#include<queue>
#include<vector>
#include<functional>
using namespace std;
struct P {
	int from, to, cost;
};
int parent[10000];
int root(int x) {
	if (parent[x] == x) return x;
	return parent[x] = root(parent[x]);
}
void unite(int x, int y) {
	x = parent[x];
	y = parent[y];
	parent[x] = y;
}
bool same(int x, int y) {
	return root(x) == root(y);
}
bool operator<(P a, P b) {
	return a.cost < b.cost;
}
bool operator>(P a, P b) {
	return a.cost > b.cost;
}
int main() {
	int n, m;
	while (cin >> n&&n != 0) {
		cin >> m;
		priority_queue<P, vector<P>, greater<P>>p;
		int a, b, c;
		for (int i = 0; i < m; i++) {
			scanf("%d,%d,%d", &a, &b, &c);
			p.push(P{ a,b,c });
		}
		for (int i = 0; i < n; i++) parent[i] = i;
		int d = 0,sum=0;
		while (d != n - 1) {
			P t = p.top(); p.pop();
			if (!same(t.from, t.to)) {
				unite(t.from, t.to);
				d++;
				sum += t.cost;
			}
		}
		sum /= 100;
		sum = sum - n + 1;
		cout << sum << endl;
	}
}