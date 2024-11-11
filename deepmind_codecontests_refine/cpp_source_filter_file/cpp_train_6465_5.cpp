#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<long long int> v(n, 0);
  int p = 0, q = 0;
  for (int i = 0; i < n; i++) {
    cin >> p;
    if (i != 0) v[i] = p - q;
    if (i == 0) v[i] = p;
    q = p;
  }
  int num = 0;
  vector<int> ans;
  for (int i = 1; i < n; i++) {
    int f = 0;
    for (int j = i; j < n; j += i) {
      for (int t = j; t < min(n, j + i); t++) {
        if (v[j] != v[j - i]) {
          f++;
          break;
        }
      }
      if (f > 0) break;
    }
    if (f == 0) {
      ans.push_back(i);
      num++;
    }
  }
  num++;
  ans.push_back(n);
  cout << num << endl;
  for (int i = 0; i < num; i++) {
    cout << ans[i] << " ";
  }
}
