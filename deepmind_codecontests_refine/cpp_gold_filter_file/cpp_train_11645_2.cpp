#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    
    ll ans = (a+b*(n-1)) - (a*(n-1)+b) + 1;
    cout << max(ans, 0LL) << endl;
}
