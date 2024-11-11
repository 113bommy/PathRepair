#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


 
int main()
{
	int n;
	cin >> n;

	ll l, r, len;
	ll pbl = 0, pbr = 0, ans = 0;
	priority_queue<ll> ql;
	priority_queue<ll, vector<ll>, greater<ll>> qr;
	
	while (n--) {
		cin >> l >> r;
		len = r - l;

		pbr += len;

		ql.push(r - pbl);
		qr.push(r - pbr);

		while ((L = ql.top() + pbl) > (R = pbr + qr.top())) {
			ans += L - R;

			ql.pop();
			qr.pop();

			ql.push(R - pbl);
			qr.push(L - pbr);
		}

		pbl -= len;
	}
	
	cout << ans << endl;
	return 0;
}