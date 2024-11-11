#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=(a);i<(b);++i)
#define allof(a) (a).begin(),(a).end()

void uniqueVector(vector< int >& vec) {
	sort(allof(vec));
	vec.erase(unique(allof(vec)), vec.end());
}

void solve(
	int n, int m,
	const vector< int >& tx, const vector< int >& ty
	) {
	vector< int > x_sort = tx, y_sort = ty;
	uniqueVector(x_sort);
	uniqueVector(y_sort);
	
	vector< vector< int > > imos(n + 1, vector< int >(n + 1, 0));
	for_(i,0,n) {
		int x = lower_bound(allof(x_sort), tx[i]) - x_sort.begin() + 1;
		int y = lower_bound(allof(y_sort), ty[i]) - y_sort.begin() + 1;
		++imos[y][x];
	}
	
	for_(y,0,n+1) for_(x,0,n) imos[y][x + 1] += imos[y][x];
	for_(x,0,n+1) for_(y,0,n) imos[y + 1][x] += imos[y][x];
	
	for_(i,0,m) {
		int lft, bot, rgt, top
		scanf("%d %d %d %d", &lft, &bot, &rgt, &top);
		
		int lx = lower_bound(allof(x_sort), lft) - x_sort.begin() + 1;
		int by = lower_bound(allof(y_sort), bot) - y_sort.begin() + 1;
		int rx = upper_bound(allof(x_sort), rgt) - x_sort.begin();
		int ty = upper_bound(allof(y_sort), top) - y_sort.begin();
		
		printf("%d\n", imos[ty][rx] - imos[ty][lx - 1] - imos[by - 1][rx] + imos[by - 1][lx - 1]);
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	
	vector< int > tx(n), ty(n);
	for_(i,0,n) scanf("%d %d", &tx[i], &ty[i]);
	
	solve(n, m, tx, ty);
}