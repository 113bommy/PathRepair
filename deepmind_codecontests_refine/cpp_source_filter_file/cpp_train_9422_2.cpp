#include <bits/stdc++.h>
#pragma GCC optimization("O2")
#pragma GCC optimization("unroll-loops")
using namespace std;
const int maxn = 100 * 1000 + 9;
pair<int, int> a[maxn];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  long long n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a, a + n);
  long long maxi = -3;
  long long t = 0;
  for (int i = 0; i < n; i++) {
    if (a[i].second < a[i - 1].second && i > 0) t = 0;
    t++;
    maxi = max(maxi, t);
  }
  cout << t - maxi;
}
