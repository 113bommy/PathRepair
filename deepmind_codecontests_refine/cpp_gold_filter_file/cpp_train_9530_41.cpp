#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  bool flag = false;
  vector<int> a, b;
  vector<string> str;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int p, q;
    string st;
    cin >> st >> p >> q;
    str.push_back(st);
    a.push_back(p);
    b.push_back(q);
  }
  for (int i = 0; i < n; i++) {
    if (a[i] >= 2400 && b[i] > a[i] && a[i] != b[i]) {
      flag = false;
      break;
    } else
      flag = true;
  }
  if (flag == true)
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
