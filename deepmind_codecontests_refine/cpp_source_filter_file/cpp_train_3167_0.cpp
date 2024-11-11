#include <bits/stdc++.h>
using namespace std;
int n, m, q, p;
int a[200001];
int b[200001];
map<int, int> counts;
map<int, int> res;
vector<int> qs;
bool IsExistInB(int data) {
  int l = 1, r = m, mid;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (b[mid] == data) {
      return true;
    } else if (b[mid] > data) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return false;
}
int main() {
  cin >> n >> m >> p;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= m; ++i) {
    cin >> b[i];
    res[b[i]]++;
  }
  sort(b, b + m);
  int start = -1, max = 0;
  for (int i = 1; i <= p; ++i) {
    start = -1;
    max = 0;
    counts.clear();
    for (int j = i; j <= n; j += p) {
      if (!IsExistInB(a[j])) {
        start = -1;
        max = 0;
        counts.clear();
      } else {
        while (counts.find(a[j]) != counts.end() && counts[a[j]] >= res[a[j]]) {
          counts[a[start]]--;
          start += p;
          --max;
        }
        start = start > 0 ? start : j;
        counts[a[j]]++;
        ++max;
        if (max == m) {
          qs.push_back(start);
        }
      }
    }
  }
  sort(qs.begin(), qs.end());
  cout << qs.size() << endl;
  for (unsigned int i = 0; i < qs.size(); ++i) cout << qs[i] << " ";
  cout << endl;
  return 0;
}
