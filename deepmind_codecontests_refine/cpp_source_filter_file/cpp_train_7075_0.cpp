#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
typedef long long ll;
const ll MD = 1e9+7;
const int MN = 210;
const int MM = 4;
const int MS = MN*MM;

int n;
string s[MN];
int si[MN];
int sd[MN];

ll inv2;
ll pow10[MS];
ll facdp[MN];

ll dp1[MN][MS], dp2[MN][MS];
ll calc() {
    inv2 = (MD+1)/2;
    pow10[0] = 1;
    for (int i = 1; i < MS; i++) {
        pow10[i] = pow10[i-1] * 10;
        pow10[i] %= MD;
    }

    for (int i = 0; i < MN; i++) {
        facdp[i] = 0;
        for (int j = 1; j <= i+1; j++) {
            ll sm = 1;
            for (int k = j; k <= i; k++) {
                sm *= k;
                sm %= MD;
            }
            facdp[i] += sm;
            facdp[i] %= MD;
        }
    }

    // for (int i = 0; i < 5; i++) {
    //     cout << facdp[i] << " ";
    // } cout << endl;
    for (int i = 0; i < n; i++) {
        si[i] = stoi(s[i]);
        sd[i] = (int)s[i].size();
    }
    memset(dp1, 0, sizeof(dp1));
    dp1[0][0] = 1;
    for (int fe = 0; fe < n; fe++) {
        int nsd = sd[fe];
        for (int i = 0; i < MN; i++) {
            for (int j = 0; j < MS; j++) {
                dp2[i][j] = dp1[i][j];
                if (i >= 1 && j >= nsd) {
                    dp2[i][j] += i*dp1[i-1][j-nsd];
                    dp2[i][j] %= MD;
                }
            }
        }
        memcpy(dp1, dp2, sizeof(dp1));
    }

    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j < 10; j++) {
    //         cout << dp1[i][j] << " ";
    //     } cout << endl;
    // }
    ll sm = 0;
    for (int fe = 0; fe < n; fe++) {
        int nsd = sd[fe];
        for (int i = 0; i < MN; i++) {
            for (int j = 0; j < MS; j++) {
                dp2[i][j] = dp1[i][j];
                if (i >= 1 && j >= nsd) {
                    dp2[i][j] -= i*dp2[i-1][j-nsd];
                    dp2[i][j] = (dp2[i][j]%MD+MD) % MD;
                }
                sm += pow10[j] * dp2[i][j] %MD * si[fe] %MD * facdp[n-i-1] %MD;
                sm %= MD;
            }
        }
    }
    return sm;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s, s+n, [&](const string &l, const string &r){
        return stoi(l) < stoi(r);
    });

    ll u = calc();
    if (s[0] == "0") {
        reverse(s, s+n);
        reverse(s, s+n-1);
        n--;
        u -= calc();
        u = (u+MD) % MD;
    }
    cout << u << endl;
    return 0;
}