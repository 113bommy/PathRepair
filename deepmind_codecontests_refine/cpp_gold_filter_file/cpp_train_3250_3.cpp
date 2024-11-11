#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int i, j, k, l, m, n, ta, tb;
  cin >> ta;
  while (ta--) {
    cin >> n;
    if (n == 0) {
      cout << 0 << endl;
      continue;
    }
    k = 0;
    m = n;
    l = 9;
    int x = 0;
    vector<long long int> v1;
    while (m) {
      l = min(l, m % 10);
      v1.push_back(m % 10);
      m = m / 10;
      k++;
    }
    bool flag = true;
    long long int x1 = v1[v1.size() - 1];
    for (i = v1.size() - 2; i >= 0; i--) {
      if (v1[i] > x1 || (v1[i] == x1 && i == 0)) {
        break;
      } else if (v1[i] < x1) {
        flag = false;
        break;
      }
    }
    j = (9 * (k - 1));
    if (flag)
      j += x1;
    else
      j += x1 - 1;
    cout << j << endl;
  }
}
