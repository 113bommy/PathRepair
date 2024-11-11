#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if((i+j)&1^1){
                v[i][j] = 1;
            }
        }
    }
    vector<pair<int, int>> ans;
    for (int i = 1; i < n; i += 6) {
        for (int j = 0; j < n; j += 2) {
            if(!v[i][j]){
                v[i][j] = 1;
                ans.emplace_back(i, j);
            }
        }
    }
    for (int i = 4; i < n; i += 6) {
        for (int j = 1; j < n; j += 2) {
            if(!v[i][j]){
                v[i][j] = 1;
                ans.emplace_back(i, j);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if(!v[i][0]){
            v[i][0] = 1;
            ans.emplace_back(i, 0);
        }
        if(!v[n-1][i]){
            v[n-1][i] = 1;
            ans.emplace_back(n-1, i);
        }
        if(!v[i][n-1]){
            v[i][n-1] = 1;
            ans.emplace_back(i, n-1);
        }
    }
    cout << ans.size() << "\n";
    for (auto &&k : ans) {
        printf("%d %d\n", k.first, k.second);
    }
    return 0;
}