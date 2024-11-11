#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[10101010],b[10101010];
main() {
    int n;
    cin >>n;
    for (int i = 0; i < n;i ++)
		cin >>a[i] >>b[i];
    sort(a,a + n);
    sort(b,b + n);
    if (n % 2 == 0) {
        cout <<ll(b[n / 2 - 1] + b[n / 2] - a[n / 2 - 1] - a[n / 2] + 1);
    }
	else {
        cout <<ll(b[n / 2] - a[n / 2] + 1);
    }
}