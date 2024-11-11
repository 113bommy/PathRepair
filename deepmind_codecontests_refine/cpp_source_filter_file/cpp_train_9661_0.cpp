#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

int n, a[100010], p, q;
vector<pair<int,int>> op;

int main(){
	cin >> n;
	p = 0;
	for (int i = 0; i < n; ++i){
		cin >> a[i];
		if (a[i] >= 0) p++;
	}
	q = n - p;
	if (p == 0){p++; q--;}
	if (q == 0){p--; q++;}
	sort(a, a+n);
	m = 0;
	for (int i = q; i < n-1; ++i){
		op.emplace_back(a[0], a[i]);
		a[0] -= a[i];
	}
	for (int i = 0; i < q; ++i){
		op.emplace_back(a[n-1], a[i]);
		a[n-1] -= a[i];
	}
	printf("%d\n", a[n-1]);
	for (auto &o: op) printf("%d %d\n", o.first, o.second);
}