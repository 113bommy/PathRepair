#include <bits/stdc++.h>
using namespace std;
long long m;
long long h1, h2, a1, a2, x1, x2, y11, y2;
int vis1[1000001];
int vis2[1000001];
vector<long long> num1;
vector<long long> num2;
int main() {
  while (cin >> m) {
    num1.clear();
    num2.clear();
    memset(vis1, 0, sizeof(vis1));
    memset(vis2, 0, sizeof(vis2));
    cin >> h1 >> a1;
    cin >> x1 >> y11;
    cin >> h2 >> a2;
    cin >> x2 >> y2;
    vis1[h1] = 1;
    vis2[h2] = 1;
    long long i = 1;
    while (1) {
      h1 = (x1 * h1 + y11) % m;
      if (vis1[h1] == 1) break;
      vis1[h1] = 1;
      if (h1 == a1) {
        num1.push_back(i);
        if (num1.size() == 1)
          memset(vis1, 0, sizeof(vis1));
        else
          break;
      }
      i++;
    }
    i = 1;
    while (1) {
      h2 = (x2 * h2 + y2) % m;
      if (vis2[h2] == 1) break;
      vis2[h2] = 1;
      if (h2 == a2) {
        num2.push_back(i);
        if (num2.size() == 1)
          memset(vis2, 0, sizeof(vis2));
        else
          break;
      }
      i++;
    }
    if (num1.size() > 0 && num2.size() > 0) {
      long long tot1 = num1[0];
      long long tot2 = num2[0];
      long long k1 = 0;
      long long k2 = 0;
      if (num1.size() == 2) k1 = num1[1] - num1[0];
      if (num2.size() == 2) k2 = num2[1] - num2[0];
      if (tot1 == tot2)
        cout << tot1 << endl;
      else {
        if (k1 == k2 && abs(tot1 - tot2) % k1 != 0)
          cout << "-1" << endl;
        else {
          for (int i = 0; i < 10000000; ++i) {
            if (tot1 == tot2)
              break;
            else if (tot1 < tot2)
              tot1 += k1;
            else
              tot2 += k2;
          }
          if (tot1 != tot2)
            cout << "-1" << endl;
          else
            cout << tot1 << endl;
        }
      }
    } else
      cout << "-1" << endl;
  }
  return 0;
}
