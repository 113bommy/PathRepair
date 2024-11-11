#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

//// < "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\a.txt" > "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\b.txt"


int main() {
	int N; cin >> N;
	while (N--) {
		int nx = 0, ny = 0;
		int amax = 0;
		pair<int, int>ans;
		while (1) {
			int dx, dy; cin >> dx >> dy;
			if (!dx&&!dy)break;
			nx += dx; ny += dy;
			if (amax < nx*nx + ny*ny||(amax==nx*nx+ny*ny&&nx>ans.first)) {
				ans = make_pair(nx, ny);
				amax = nx*nx + ny*ny;
			}
		}
		cout << ans.first<<" "<<ans.second << endl;
	}
	return 0;
}