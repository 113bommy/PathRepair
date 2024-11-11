#include<bits/stdc++.h>

using namespace std;

// A, B, S
// B = S - A
// X, X+D, X+2D, X+3D, ... X+(N-1)D
// X+iD = nX+sD ( s = \sigma ^ n)
// (m-n)X + (s-t)D = 0


int main(void) {
    long n, x, d;
    cin >> n >> x >> d;

    if(d==0) {
        if(x==0)
            cout << 1 << endl;
        else
            cout << n+1 << endl;
        return 0;
    }

    if(d < 0)
        x = -x, d = -d;

    map<long, vector<pair<long,long>>> slot;

    for(long c=0; c<=n; c++) {
        long a = c*(c-1)/2;
        long b = c*(n-1 + n-c)/2;

        slot[(d+((c*x)%d))%d].push_back({c*x/d + a, c*x/d + b +1});
    }

    long r = 0;
    for(auto &w: v) {
        auto &l = w.second;

        // my きれい algorithm
        sort(l.begin(), l.end());
        long a = -1e18, b = -1e18;
        for(auto &x: l) {
            a = max(x.first, b);
            b = max(x.second, a);
            r += b - a;
        }
    }
    cout << r << endl;
}
