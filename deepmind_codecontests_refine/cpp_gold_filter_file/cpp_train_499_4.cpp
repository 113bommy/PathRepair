#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    ll ans = min(A*X+B*Y, min(2*C*max(X,Y), 2*C*min(X,Y)+A*max(0,X-Y)+B*max(0,Y-X)));

    cout << ans << "\n";
}
