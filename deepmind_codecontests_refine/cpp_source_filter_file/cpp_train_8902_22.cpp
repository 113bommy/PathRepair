#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> v;
  int n, first, second;
  cin >> n;
  char c;
  string a;
  cin >> a;
  for (int i = 0; i < n; i++) {
    int b;
    cin >> b;
    v.push_back(b);
  }
  int count = 0, i = 0;
  while (n != count) {
    if (a[i] == '>') {
      first = v[i];
      if (i + first <= n) {
        i = i + first;
        count++;
      } else {
        cout << "FINITE" << endl;
        return 0;
      }
    }
    if (count >= n) {
      break;
    }
    if (a[i] == '<') {
      first = v[i];
      if (i - first >= 0) {
        i = i - first;
        count++;
      } else {
        cout << "FINITE" << endl;
        return 0;
      }
    }
    if (count >= n) {
      break;
    }
  }
  cout << "INFINITE" << endl;
}
