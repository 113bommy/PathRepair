# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <bitset>
# include <complex>
#include<limits.h>
#include<unordered_map>
#include<unordered_set>
#include<deque>
#include<cstdio>
typedef long long int ll;
#define FOR(i,a,n) for(int i=(ll)a;i<(ll)n;++i)
#define TFOR(i,n)FOR(i,0,n)
#define ALL(x) x.begin(),x.end();
const int INF = 1LL << 30;
const ll LLINF = 1LL << 60;
int main() {
	int n, q;
	std::cin >> n >> q;
	int max = 0;
	std::bitset<???00000> bit;
	TFOR(i, n) {
		int nn;
		std::cin >> nn;
		bit[nn-1] = 1;
		if (max < nn)max = nn;
	}
	TFOR(i, q) {
		int nn;
		std::cin >> nn;
		bool fl = 0;
		for (int j = nn-1; j>=0; --j) {
			for (int k =max/nn*nn+j; k > 0; k -= nn) {
				if (bit[k - 1] == 1) { std::cout << j << std::endl; fl = 1; }
				if (fl == 1)break;
			}
			if (fl == 1) { fl = 0; break; }
		}
	}
	return 0;
}