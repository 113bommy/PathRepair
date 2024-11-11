#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  int finans = 0;
  cin >> n >> k;
  vector<int> s(n, 0);
  vector<pair<int, int> > p;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    p.push_back(make_pair(10 - s[i] % 10, i));
  }
  sort(p.begin(), p.end());
  int j = 0;
  while (k > 0) {
    if (j == n) break;
    int temp = p[j].first;
    if (k >= temp) {
      if (temp == 10) break;
      k -= temp;
      s[p[j].second] += temp;
      j++;
    } else
      break;
  }
  if (k / 10 > 1) finans += k / 10;
  for (int i = 0; i < n; i++) finans += s[i] / 10;
  finans = min(finans, 10 * n);
  cout << finans << endl;
}
