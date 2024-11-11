#include <bits/stdc++.h>
using namespace std;
int a[(1 << 21) + 1];
int wid(int i) {
  if (a[2 * i] == 0 && a[2 * i + 1] == 0) {
    return i;
  } else {
    if (a[2 * i] > a[2 * i + 1]) {
      return wid(2 * i);
    } else {
      return wid(2 * i + 1);
    }
  }
}
void f(int i) {
  if (a[2 * i] == 0 && a[2 * i + 1] == 0)
    a[i] = 0;
  else {
    if (a[2 * i] > a[2 * i + 1]) {
      a[i] = a[2 * i];
      f(2 * i);
    } else {
      a[i] = a[2 * i + 1];
      f(2 * i + 1);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int h, g, t;
  cin >> t;
  while (t--) {
    cin >> h >> g;
    int n = (1 << h);
    vector<int> x;
    for (int i = 1; i < (1 << (h + 1)); ++i) {
      if (i < n)
        cin >> a[i];
      else
        a[i] = 0;
    }
    int index = (1 << g) - 1;
    for (int i = 1; i < (1 << g); ++i) {
      int t = wid(i);
      while (t > index) {
        x.push_back(i);
        f(i);
        if (x.size() == (1 << h) - (1 << g)) break;
        t = wid(i);
      }
      if (x.size() == (1 << h) - (1 << g)) break;
    }
    int sum = 0;
    for (int i = 1; i < (1 << g); ++i) sum += a[i];
    cout << sum << '\n';
    for (int i = 0; i < x.size(); ++i) cout << x[i] << " ";
    cout << '\n';
  }
  return 0;
}
