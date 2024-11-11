#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
int main() {
    int N;
    cin >> N;
    ll t, a, A = 1, T = 1;
    REP(i, N) {
        cin >> t >> a;
        ll n = max((T + t - 1) / t, (A + a - 1) / a);
        T = n * t;
        A = n * a;
    }
    cout << T + A << endl;
}