#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int a[n], t[n];
  int h[k];
  for (int i = 1; i <= k; i++) h[i] = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    h[a[i]]++;
  }
  for (int i = 0; i < n; i++) cin >> t[i];
  vector<pair<int, int> > l;
  for (int i = 0; i < n; i++) {
    l.push_back(make_pair(t[i], a[i]));
  }
  long long int skait = 0;
  for (int i = 1; i <= k; i++)
    if (h[i] == 0) skait++;
  sort(l.begin(), l.end());
  long long int s = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    if (s >= skait) break;
    if (h[l[i].second] > 1) {
      sum += l[i].first;
      h[l[i].second]--;
      s++;
    }
  }
  cout << sum << endl;
  return 0;
}
