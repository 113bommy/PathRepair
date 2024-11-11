#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n , m;

const int N = 1e5 + 5;

int a[N << 1] , ans;

bool check(int k){
	int mx = 0;
	for(int i = 1; i <= k; i++)
		mx = max(mx , a[i] +  a[2 * k - i + 1]);
	for(int i = 1; i <= n - k; i++){
		int x = a[2 * k + i] + a[2 * n - i + 1];
		if (x < m)
			 return 0;
		mx = max(mx , x - m);
	}
	ans = min(ans , mx);
	return 1;
}

int main(){
	cin >> n >> m;
	ans = m;
	for(int i = 1; i <= 2 * n; i++)
		cin >> a[i];
	sort(a + 1 , a + 2 * n + 1);
	int l = 0 , r = n;
	while(l <= r){
		int mid = l + r >> 1;
		if(check(mid))
			r = mid - 1;
		else
			l = mid + 1;
	}
	cout << ans << end;
    return 0;
}