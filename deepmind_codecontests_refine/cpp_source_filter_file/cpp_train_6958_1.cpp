#include<bits/stdc++.h>
using namespace std;
long long q,h,s,d,n,x;
int main() {
	ios::sync_with_stdio(false);
	cin >> q >> h >> s >> d >> n;
	x = min(q * 4,min(h * 2,s));
	cout << min(x * n,n / 2 * d + (n & 2) * x)) << endl;
	return 0;
}