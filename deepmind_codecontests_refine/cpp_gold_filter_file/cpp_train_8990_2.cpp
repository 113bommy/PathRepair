#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  cin >> n;
  vector<pair<int, int> > v(n);
  for (i = 0; i < n; i++) {
    cin >> v[i].second >> v[i].first;
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  int h = n - 1;
  int g = 0;
  while (v[h].first == 0) h--;
  while (v[g].first == 100) g++;
  vector<pair<double, int> > w;
  for (i = g; i <= h; i++) {
    pair<double, int> lol;
    double p = v[i].first / 100.0;
    lol.first = v[i].second * p / (1 - p);
    lol.second = i;
    w.push_back(lol);
  }
  sort(w.begin(), w.end());
  reverse(w.begin(), w.end());
  vector<pair<int, int> > v6(n);
  for (i = 0; i < n; i++) v6[i] = v[i];
  for (i = g; i <= h; i++) v6[i] = v[w[i - g].second];
  vector<long long> dislikes(n);
  dislikes[n - 1] = 0;
  for (i = n - 2; i >= 0; i--)
    dislikes[i] = dislikes[i + 1] + (100 - v6[i + 1].first);
  long double sum = 0;
  cout.precision(10);
  for (i = 0; i < n; i++) {
    sum += v6[i].second;
    sum += v6[i].first * v6[i].second * dislikes[i] / 10000.0;
  }
  cout << sum;
}
