#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int x[n], y[n], k = 0, sum = 0, sinolo = 0;
  vector<pair<double, double> > p;
  vector<int> katakorifes, e;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (x[i] == x[j]) {
        bool y = false;
        for (int l = 0; l < katakorifes.size(); l++)
          if (katakorifes[l] == x[i]) y = true;
        if (y == false) katakorifes.push_back(x[i]);
      } else {
        p.push_back(pair<double, double>(1e9 + 9, 1e9 + 9));
        p[k].first = (float(y[i] - y[j])) / (x[i] - x[j]);
        p[k].second = y[i] - p[k].first * x[i];
        k++;
      }
    }
  }
  sort(p.begin(), p.begin() + k);
  sort(katakorifes.begin(), katakorifes.begin() + katakorifes.size());
  int katak = 1;
  if (katakorifes.size() == 0) katak = 0;
  for (int i = 1; i < katakorifes.size(); i++)
    if (katakorifes[i] != katakorifes[i - 1]) katak++;
  int j = 0;
  e.push_back(1);
  for (int i = 1; i < k; i++) {
    if (p[i].first != 1e9 + 9) {
      if (p[i].first == p[i - 1].first && p[i].second != p[i - 1].second)
        e[j]++;
      else if (p[i].first != p[i - 1].first) {
        e.push_back(1);
        j++;
      }
    }
  }
  e.push_back(katak);
  j++;
  for (int i = 0; i <= j; i++) {
    sinolo += e[i];
  }
  for (int i = 0; i <= j; i++) {
    sum += (sinolo - e[i]) * e[i];
  }
  cout << sum / 2 << "\n";
  return 0;
}
