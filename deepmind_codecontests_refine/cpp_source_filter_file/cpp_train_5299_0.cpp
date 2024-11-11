#inlucde <cstdio>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
#define repa(i,s,e) for(int i=s; i<=e; i++)
#define repd(i,s,e) for(int i=s; i>=e; i--)

const int R_MAX = 100011;
int n, k, m, r;
int ans[R_MAX];

void add(int d) {
	ans[0] += 1 / d;
	int res = 1 % d;
	repa(i,1,r+10) {
		res *= 10;
		ans[i] += res / d;
		if(res % d == 0) break;
		res = res % d;
	}

	repd(i,r+10,0) {
		if(ans[i] >= 10) {
			int u = ans[i] / 10;
			ans[i] = ans[i] % 10;
			ans[i-1] += u;
		}
	}
}

void div(int d) {
	int res = 0;
	rep(i,r+10) {
		res += ans[i];
		ans[i] = res / d;
		res = res % d;
		res *= 10;
	}
}

int main() {
	while(cin>>n>>k>>m>>r, n|k|m|r) {
		memset(ans, 0, sizeof(int) * R_MAX);
		if(m == 0) {
			add(n);
		} else {
			repa(i,1,n-1) {
				add(i);
			}
			div(n);
			add(n);
		}

		printf("%d.", ans[0]);
		repa(i,1,r) printf("%d", ans[i]);
		printf("\n");
	}
}