#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, w;
  cin >> n;
  vector<int> t(n);
  for (int i = 0; i < n; i++) cin >> t[i];
  int ones, twos, threes = 0;
  for (int i = 0; i < n; i++) {
    if (t[i] == 1) ones++;
    if (t[i] == 2) twos++;
    if (t[i] == 3) threes++;
  }
  w = min(ones, min(twos, threes));
  cout << w << endl;
  vector<int> a, b, c;
  for (int i = 0; i < n; i++) {
    if (t[i] == 1) a.push_back(i + 1);
    if (t[i] == 2) b.push_back(i + 1);
    if (t[i] == 3) c.push_back(i + 1);
  }
  for (int i = 0; i < w; i++)
    cout << a[i] << " " << b[i] << " " << c[i] << endl;
}
