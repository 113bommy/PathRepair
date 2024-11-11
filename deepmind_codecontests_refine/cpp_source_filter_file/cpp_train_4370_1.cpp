#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
const int M = 1000000007;

long long cnt(long long n) {
    return n - n / 3 - n / 5 + n / 15;
}

long long len(long long n) {
    long long ret = (n / 3 + n / 5) * 4;
    long long l = 0, r = min(9, n), t = 1;
    while (l < n) {
        ret += (cnt(r) - cnt(l)) * t;
        ++t;
        l = r;
        r = min(r * 10 + 9, n);
    }
    return ret;
}

int main() {
    long long n;
    cin >> n;
    --n;
    long long ok = 0, ng = 1e18;
    while (ok + 1 < ng) {
        long long m = (ok + ng) / 2;
        if (len(m) <= n)
            ok = m;
        else
            ng = m;
    }
    string s = "";
    for (int i = 0; i < 20; ++i) {
        long long j = ok + 1 + i;
        if (!(j % 3)) s += "Fizz";
        if (!(j % 5)) s += "Buzz";
        if (j % 3 && j % 5) s += to_string(ok + 1 + i);
    }
    cout << s.substr(n - len(ok), 20) << "\n";
    return 0;
}

