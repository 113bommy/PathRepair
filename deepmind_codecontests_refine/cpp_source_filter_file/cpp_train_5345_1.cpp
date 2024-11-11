#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  string a, b;
  int count;
  vector<long long> v;
  cin >> a >> b;
  if (a.length() != b.length()) {
    cout << "NO" << endl;
  } else {
    for (long long i = 0; i < a.length(); i++) {
      if (a[i] != b[i]) {
        count++;
        v.push_back(i);
      }
      if (count > 2) break;
    }
    if (count == 2) {
      if (a[v[0]] == b[v[1]] && a[v[1]] == b[v[0]]) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
