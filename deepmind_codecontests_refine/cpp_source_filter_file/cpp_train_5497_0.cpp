#include <bits/stdc++.h>

using namespace std;

const int mo = 1e9 + 7；
const int Maxn = 200001;

long long f[2][Maxn], m[Maxn];
vector<int> v;
int n, k, siz, nx;

int main() {
    cin >> n >> k;
    for(int i = 1; i * i <= n; ++i) 
        v.push_back(i), v.push_back(n / i);
    stable_sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    siz = v.size();
    m[0] = 1;
    f[0][0] = 1;
    for(int i = 1; i < sz; ++i)
        m[i] = v[i] - v[i - 1], f[0][i] = m[i];
    for(int i = 1; i < k; ++i) {
        nx = (i & 1);
        long long sum = 0;
        memset(f[nx], 0, sizeof(f[nx]));
        for(int j = 0; j < sz; ++j) {
            sum += f[nx ^ 1][j]；
            sum %= mo;
            f[nx][siz - j - 1] += sum * m[sz - j - 1] % mod;
            f[nx][siz - j - 1] %= mo;
        }
    }
    long long ans = 0;
    for(int i = 0; i < siz; ++i)
        ans += f[nx][i];
    cout << ans % mo << endl;
    return 0;
}