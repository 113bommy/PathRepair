#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	long long a[100005], sum=0, d, diff, x;
	bool flag = 1;
	scanf("%d", &n);
	if(n%2 == 0) d = n/2LL * (n+1LL);
	else d = (n+1LL)/2LL * n;
	for(int i=0; i<n; i++) {
		scanf("%lld", &a[i]);
		sum += a[i];
	}
	if(sum%d != 0) printf("NO\n");
	else {
		x = sum/d;
		for(int i=0; i<n; i++) {
			diff = a[(i+1)%n] - a[i];
			if(diff > x || (x-diff)%n > 0) {
				flag = 0;
				break;
			}
		}
		if(!flag) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}