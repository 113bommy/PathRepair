#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e5 + 100;
const int maxm = (int)1e6 + 100;
const int mod = (int)1e9 + 7;
int n, m, a[maxn], cnt1[maxn], can[maxn], cnt2[maxn], tot, cnt;
char second[maxn];
int main() {
  cin >> n >> m;
  for (int i = (1); i <= (n); ++i) {
    char type;
    cin >> type >> a[i];
    second[i] = type;
    if (type == '+')
      cnt1[a[i]]++;
    else
      cnt2[a[i]]++, tot++;
  }
  for (int i = (1); i <= (n); ++i) {
    if (cnt1[i] + tot - cnt2[i] == m) cnt++, can[i] = 1;
  }
  for (int i = (1); i <= (n); ++i) {
    if (second[i] == '+') {
      if (!can[a[i]])
        cout << "Lie\n";
      else {
        if (cnt <= 1)
          cout << "Truth\n";
        else
          cout << "Not defined\n";
      }
    } else {
      if (!can[a[i]])
        cout << "Truth\n";
      else {
        if (cnt == 1)
          cout << "Lie\'n";
        else
          cout << "Not defined\n";
      }
    }
  }
}
