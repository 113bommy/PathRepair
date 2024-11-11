#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using long long ll;

int main() {
	int n;
	ll ans = 0;
	vector<int>::iterator pos1, pos2;
	cin >> n;
	vector<int>a(n), b(n), c(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> b[i];
	for (int i = 0; i < n; ++i) cin >> c[i];
	sort(a.begin(), a.end());
	sort(c.begin(), c.end());
	for (int i = 0;i < n; ++i) {
		pos1=lower_bound(a.begin(),a.end(),b[i]);
		pos2=upper_bound(c.begin(),c.end(),b[i]);//aとcは互いに独立
		ans +=distance(a.begin(),pos1)*abs(distance(c.end(),pos2));
	}
	cout << ans << endl;
}