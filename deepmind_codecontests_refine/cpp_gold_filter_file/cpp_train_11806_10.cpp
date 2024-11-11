#include <bits/stdc++.h>
using namespace std;
const int N = int(1e5);
vector<int> a, d, ciel;
int sum, cnt[N];
bool used[N];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string type;
    int s;
    cin >> type >> s;
    if (type == "ATK") {
      a.push_back(s);
      sum -= s;
      s++;
    } else
      d.push_back(s);
    cnt[s]--;
  }
  for (int j = 0; j < m; j++) {
    int s;
    cin >> s;
    ciel.push_back(s);
    sum += s;
    cnt[s + 1]++;
  }
  bool ok = 1;
  int bal = 0;
  for (int j = 8001; j >= 0; j--) {
    bal += cnt[j];
    if (bal < 0) {
      ok = 0;
    }
  }
  sort(ciel.begin(), ciel.end());
  if (ok) {
    for (int i = 0; i < (int)(d).size(); i++) {
      for (int j = 0; j < (int)(ciel).size(); j++) {
        if (!used[j]) {
          if (ciel[j] > d[i]) {
            sum -= ciel[j];
            used[j] = 1;
            break;
          }
        }
      }
    }
  }
  int res = ok ? sum : 0;
  sum = 0;
  sort(a.begin(), a.end());
  reverse(ciel.begin(), ciel.end());
  for (int i = 0; i < min((int)(a).size(), (int)(ciel).size()); i++) {
    if (ciel[i] > a[i]) sum += ciel[i] - a[i];
  }
  cout << max(res, sum) << endl;
  return 0;
}
