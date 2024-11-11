#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  vector<pair<long int, int>> a, b;
  for (int i = 0; i < n; i++) {
    long int s;
    pair<long int, int> p;
    cin >> s;
    p.first = s;
    p.second = i;
    a.push_back(p);
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    pair<long int, int> p;
    if (i == 0) {
      p.first = a[i].first;
      p.second = a[i].second;
      b.push_back(p);
      continue;
    }
    if (a[i].first > b[i - 1].first) {
      p.first = a[i].first;
      p.second = a[i].second;
      b.push_back(p);
    } else {
      p.first = a[i].first + 1;
      p.second = a[i].second;
      b.push_back(p);
    }
  }
  long int s[400000]{0};
  for (int i = 0; i < n; i++) {
    s[b[i].second] = b[i].first;
  }
  for (int i = 0; i < n; i++) cout << s[i] << " ";
  return 0;
}
