#include <bits/stdc++.h>

using namespace std;

int n;
long long k;
int a[200100], f[200100];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> f[i];
	sort(a, a + n);
	sort(f, f + n, greater<int>());

	long long l = 0, r = 1e12;
	while(l < r){
		long long mid = l + (r - l) / 2;
		long long need = 0;
		for(int i = 0; i < n; i++) need += max(0, a[i] - mid / f[i]);
		if(need <= k) r = mid;
		else l = mid + 1;
	}

	cout << l << endl;
}