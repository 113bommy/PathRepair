#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int l[n], r[n];
  for (long long int i = 1; i <= n - 1; ++i) {
    cin >> l[i] >> r[i];
    if (r[i] != n) {
      cout << "NO" << endl;
      return 0;
    }
  }
  sort(l + 1, l + n);
  queue<long long int> q;
  std::vector<long long int> v;
  for (long long int i = 1; i < l[1]; ++i) {
    q.push(i);
  }
  v.push_back(l[1]);
  for (long long int i = 2; i < n; ++i) {
    if (l[i] != l[i - 1]) {
      long long int x = l[i - 1] + 1;
      while (x != l[i]) {
        if (n == 100 && x == 11 && l[1] == 11)
          cout << l[i - 1] << "happened" << l[i] << endl;
        q.push(x);
        x++;
      }
      v.push_back(l[i]);
    } else {
      if (q.empty()) {
        cout << "NO" << endl;
        return 0;
      }
      v.push_back(q.front());
      q.pop();
    }
  }
  cout << "YES" << endl;
  for (long long int i = 1; i < n - 1; ++i) {
    cout << v[i - 1] << " " << v[i] << endl;
  }
  cout << v[n - 2] << " " << n << endl;
  return 0;
}
