#include <bits/stdc++.h>
using namespace std;
int main() {
  int long long m, n, sum, a[100001], b[100001];
  vector<int long long> s1, s;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> sum;
    s1.push_back(sum);
  }
  for (int i = 0; i < n; i++) {
    cin >> sum;
    s.push_back(sum);
  }
  sort(s1.begin(), s1.end());
  sort(s.begin(), s.end());
  for (int i = 0; i < n; i++) {
    a[i] = s1[i];
    b[n - i - 1] = s[i];
  }
  int i = 0, j = 0, t = 0;
  while (i < n && j < n) {
    if (a[i] + b[j] >= m) {
      i++;
      j++;
      t++;
    } else if (i < n - 1 && a[i] <= a[i + 1]) {
      i++;
    } else {
      j++;
    }
  }
  cout << 1 << " " << t;
  return 0;
}
