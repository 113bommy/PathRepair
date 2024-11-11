#include <bits/stdc++.h>
#define N 100010
#define P 1000000007
using namespace std;

int n;
long long a[N], inv[N], sum[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sum[0] = 0, inv[1] = 1;
    for (int i = 1; i <= n; ++i) {
        if (i > 1) inv[i] = (P - P / i) * inv[P % i] % P;
        sum[i] = (sum[i - 1] + inv[i]) % P;
    }
    long long ret = 0, fact = 1;
    for (int i = 1; i <= n; ++i) 
        ret = (ret + (sum[i] + sum[n - i + 1] - 1) * a[i]) % P, fact = fact * i % P;
    cout << ret * fact % P << endl;  
    return 0;
}