#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int Q,H,S,D;
    int N;
    cin >> Q >> H >> S >> D >> N;
    int L1 = min({Q*4,Q*2+H,H*2,S});
    cout << min(L1*N,N/2*D+N%2*L1) << endl;
}