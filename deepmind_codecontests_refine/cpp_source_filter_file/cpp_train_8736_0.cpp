#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; int i; bool used; };
 
int MOD = 1000000007;

int main() {
	int d, n, b; cin >> d >> n >> b;
	vector<int> p(n), h(n);
	for (int i = 0; i < n; i++) cin >> p[i] >> h[i];
	double ans = FLT_MAX;
	for (int t = 1; t <= b + 1; t++) {
		double l = (double)d / t;
		double lb = 0, ub = 1000000;
		for (int k = 0; k < 100; k++) {
			double vy = (lb + ub) / 2;
			double vx = l / (vy * 2);
			bool flag = true;
			for (int i = 0; i < n; i++) {
				double x = fmod(p[i], l);
				double y = x * vy / vx - x * x / (vx * vx * 2);
				if (y < h[i]) flag = false;
			}
			if (flag) ub = vy;
			else lb = vy;
		}
		double vy = max(lb, sqrt(l / 2)), vx = l / (vy * 2);
		ans = min(ans, sqrt(vx * vx + vy * vy));
	}
	printf("%.10f\n", ans);
} 