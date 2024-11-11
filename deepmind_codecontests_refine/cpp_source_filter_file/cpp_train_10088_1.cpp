#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n;
ll a[1000010];
ll *p, *q;

int main() {
	while (cin >> n, n)
	{
		ll res = 0, t, s, color;
		for (int i = 0; i < n;i++)scanf_s("%lld", &a[i]);
		sort(a, a + n);
		color = a[0];
		t=res = upper_bound(a, a + n, a[0]) - lower_bound(a, a + n, a[0]);
		for (p = &a[0]; t < n; ) {
			p = upper_bound(a, a + n, *p);
			s = upper_bound(a, a + n, *p) - lower_bound(a, a + n, *p);
			t += upper_bound(a, a + n, *p) - lower_bound(a, a + n, *p);
			if (res < s) {
				res = s;
				color = *p;
			}
		}
		if (2 * res > n ) { cout << color << endl; }
		else cout << "NO COLOR" << endl;
	
	}
}