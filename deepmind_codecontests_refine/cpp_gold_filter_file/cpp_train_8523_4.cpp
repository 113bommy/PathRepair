#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;

char buf[10];
int main() {
	int a[4], b[4];
	while (gets(buf), strcmp(buf, "0 0")) {
		char*s = buf;
		rep(i, 4) { sscanf(s, "%1d", &a[i]); s += 1; }s += 1;
		rep(i, 4) { sscanf(s, "%1d", &b[i]); s += 1; }
		int hit = 0, blow = 0;
		rep(i, 4)if (a[i] == b[i])hit++;
		rep(i, 4) if (find(a, a + 4, b[i]) != a + 4)blow++;
		cout << hit << ' ' << blow - hit << endl;
	}
	return 0;
}