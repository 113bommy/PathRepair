#include <bits/stdc++.h>
using namespace std;
int t[200001];
int t0[200001];
vector<pair<int, int> > stos;
vector<int> w;
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    scanf("%d", &t[i]);
    t0[i] = t[i];
  }
  pair<int, int> a;
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &a.first, &a.second);
    while (!stos.empty() && stos.back().second < a.second) stos.pop_back();
    stos.push_back(a);
  }
  stos.push_back(make_pair(0, 0));
  sort(t, t + stos[0].second - 1);
  int l = 0, p = stos[0].second - 1;
  for (int i = 0; i < stos.size() - 1; i++) {
    if (stos[i].first == 1) {
      for (int j = 0; j < stos[i].second - stos[i + 1].second; j++)
        w.push_back(t[p - j]);
      p -= stos[i].second - stos[i + 1].second;
    } else {
      for (int j = 0; j < stos[i].second - stos[i + 1].second; j++)
        w.push_back(t[l + j]);
      l += stos[i].second - stos[i + 1].second;
    }
  }
  for (int i = w.size() - 1; i >= 0; i--) printf("%d ", w[i]);
  for (int i = w.size(); i < n; i++) printf("%d ", t0[i]);
}
