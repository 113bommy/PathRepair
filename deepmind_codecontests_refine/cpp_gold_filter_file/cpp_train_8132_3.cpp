#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
long long n, m, a[maxn + 4], k, id[maxn + 3], counter;
int kt[maxn + 3], dem, ans = 0;
vector<int> d;
vector<int>::iterator it, w;
string s;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  cin >> m;
  while (m-- > 0) {
    cin >> k >> n;
    cout << 9 * (k - 1) + n << "\n";
  }
}
