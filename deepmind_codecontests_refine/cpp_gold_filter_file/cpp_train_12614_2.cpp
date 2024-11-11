#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
const long long mod = 1e9 + 7;
string en = "\n";
long long a[N], d[N];
map<int, int> used;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ;
  int n, z = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (used[a[i]] > 0) {
      z++;
    }
    used[a[i]]++;
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    if (z > 1 || used[a[i]] > 2 ||
        used[a[i]] > 1 && (used[a[i] - 1] > 0 || a[i] == 0)) {
      cout << "cslnb";
      return 0;
    }
  }
  long long c = 0, sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += a[i] - c;
    c++;
  }
  if (sum % 2 == 1) {
    cout << "sjfnb";
    return 0;
  }
  cout << "cslnb";
  return 0;
}
