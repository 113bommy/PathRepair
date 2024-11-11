#include <iostream>
#include <algorithm>

using namespace std;

using ll =  long long;

int main() {
    ll n, u, v;
    cin >> n;
    ll ans = (n * (n+1) * (2*n+1) / 6 + n * (n+1) / 2) / 2;
    for(int i=0;i<n-1;++i) {
        cin >> u >> v;
        if(u < v) ans -= u*(N-v+1);
        else ans -= v*(N-u+1);
    }
    cout << ans << endl;
}
