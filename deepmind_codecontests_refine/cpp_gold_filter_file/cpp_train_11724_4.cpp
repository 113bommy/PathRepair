#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<pair<long long, int> > a;
int sorrend[600004];
int tart;
long long valasz;
int ki[600004];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  tart = k + 1;
  for (int i = 1; i <= n; i++) {
    int A;
    cin >> A;
    a.push_back({A, i});
  }
  sort(a.begin(), a.end());
  for (int i = a.size() - 1; i >= 0; i--) {
    if (tart < a[i].second) {
      sorrend[a[i].second] = a[i].second;
      ki[a[i].second] = a[i].second;
    } else {
      sorrend[tart] = a[i].second;
      ki[a[i].second] = tart;
      valasz += a[i].first * (tart - a[i].second);
    }
    while (sorrend[tart] != 0) tart++;
  }
  cout << valasz << endl;
  for (int i = 1; i <= n; i++) cout << ki[i] << " ";
}
