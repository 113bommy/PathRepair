#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

#define NIL -1
#define N 100005

struct Node{ int p, l, r; };

Node T[N];
int n, D[N], H[N];

void setDepth(int u, int d){
	if (NIL == u) return;
	D[u] = d;
	setDepth(T[u].l, d + 1);
	setDepth(T[u].r, d + 1);
}

int setHeight(int u){
	int h1 = 0, h2 = 0;
	if (NIL != T[u].l) h1 = setHeight(T[u].l) + 1;
	if (NIL != T[u].r) h2 = setHeight(T[u].r) + 1;

	return H[u] = max(h1, h2);
}

int getSibling(int u){
	if (NIL == T[u].p) return NIL;
	if (T[T[u].p].l != u && T[T[u].p].r != NIL) return T[T[u].p].l;
	if (T[T[u].p].r != u && T[T[u].p].l != NIL) return T[T[u].p].r;
	return NIL;
}

void print(int u){
	printf("node %d: ", u);
	printf("parent = %d, ", T[u].p);
	printf("sibling = %d, ", getSibling(u));

	int d = 0;
	if (NIL != T[u].l) d++;
	if (NIL != T[u].r) d++;

	printf("degree = %d, ", d);
	printf("depth = %d, ", D[u]);
	printf("height = %d, ", H[u]);

	if (NIL == T[u].p) printf("root\n");
	else if (NIL == T[u].l && NIL == T[u].r) printf("leaf\n");
	else printf("internal node\n");
}

int main1()
{
	int root = 0; cin >> n;
	for (int i = 0; i < n; ++i) T[i].p = NIL;

	for (int i = 0; i < n; ++i){
		int v, l, r; cin >> v >> l >> r;
		T[v].l = l;
		T[v].r = r;
		if (NIL != l) T[l].p = v;
		if (NIL != r) T[r].p = v;
	}

	for (int i = 0; i < n; ++i) if (NIL == T[i].p) root = i;
	setDepth(root, 0);
	setHeight(root);

	for (int i = 0; i < n; ++i) print(i);

	return 0;
}