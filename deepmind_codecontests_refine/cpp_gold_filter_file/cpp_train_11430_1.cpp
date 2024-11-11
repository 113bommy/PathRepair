#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 200000


int main() {
	int a[N];
	int b[N];
	int c[N];
	int d[N];
	vector<int>e;
	f(i, N) {
		a[i] = 0;
		b[i] = 0;
		c[i] = 0;
      d[i]=0;
	}
	int n, k;
	int x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &n);
	f(i, n) {
		scanf("%d", &a[i]);
		a[i]--;
	}
	if (n == 2) {
		printf("-1\n");
		return 0;
	}
	f(i, n) {
		b[a[i]]++;
	}
	f(i, n)c[b[i]]++;
	x = 0;
	y = 1;
	z = -1;
	f(i, n) {
		if (((n - i - 1) > 1) && (c[n - i - 1] > 0)) {
			if (b[x] == (n - i - 1))k = x;
			else {
				for (int j = y; j < n; j++) {
					if (b[j] == (n - i - 1))k = j;
				}
			}
			d[i] = k;
			if (x != k)e.push_back(x);
			for (int j = y; j < n; j++) {
				if (j != k)e.push_back(j);
			}
			f(j, e.size()) {
				d[i + j + 1] = e[j];
			}
			if (a[d[i]] == d[i + 1])swap(d[i + 1], d[i + 2]);
			break;
		}
		if (z != x) {
			d[i] = x;
			z = a[x];
			b[a[x]]--;
			c[b[a[x]]]++;
			c[b[a[x]] + 1]--;
			c[b[x]]--;
			x = y;
			y = y + 1;
		}
		else {
			d[i] = y;
			z = a[y];
			b[a[y]]--;
			c[b[a[y]]]++;
			c[b[a[y]] + 1]--;
			c[b[y]]--;
			y = y + 1;
		}
	}
  bool g[N];
  f(i,N)g[i]=false;
	if (d[n - 1] >= n) {
		f(i,n-3)g[d[i]]=true;
      e.clear();
      f(i,n)if(!g[i])e.push_back(i);
		sort(e.begin(), e.end());
		if ((a[d[n - 4]] != e[0]) && (a[e[0]] != e[1]) && (a[e[1]] != e[2])) {
			d[n - 3] = e[0];
			d[n - 2] = e[1];
			d[n - 1] = e[2];
		}
		else if ((a[d[n - 4]] != e[0]) && (a[e[0]] != e[2]) && (a[e[2]] != e[1])) {
			d[n - 3] = e[0];
			d[n - 2] = e[2];
			d[n - 1] = e[1];
		}
		else if((a[d[n - 4]] != e[1]) && (a[e[1]] != e[0]) && (a[e[0]] != e[2])) {
			d[n - 3] = e[1];
			d[n - 2] = e[0];
			d[n - 1] = e[2];
		}
		else if((a[d[n - 4]] != e[1]) && (a[e[1]] != e[2]) && (a[e[2]] != e[0])) {
			d[n - 3] = e[1];
			d[n - 2] = e[2];
			d[n - 1] = e[0];
		}
		else if((a[d[n - 4]] != e[2]) && (a[e[2]] != e[0]) && (a[e[0]] != e[1])) {
			d[n - 3] = e[2];
			d[n - 2] = e[0];
			d[n - 1] = e[1];
		}
		else {
			d[n - 3] = e[2];
			d[n - 2] = e[1];
			d[n - 1] = e[0];
		}
	}
f(i,n-1){
  if(a[d[i]]==d[i+1])swap(d[i],d[i+1]);
}
	f(i, n) {
		printf("%d", d[i] + 1);
		if (i < (n - 1))printf(" ");
		else printf("\n");
	}

	return 0;
}
