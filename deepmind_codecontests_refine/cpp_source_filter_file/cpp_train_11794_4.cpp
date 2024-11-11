#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5 + 5, AL = 26;
long long n, a[MAX_N];
vector<int> li, ri, beg[AL], rev[AL];
string second;
int mrg(int l, int r) {
  if (l == r) {
    return 0;
  }
  if (l == r - 1) {
    bool b = false;
    if (a[l] > a[l + 1]) {
      b = true;
      swap(a[l], a[l + 1]);
    }
    return b;
  }
  int mid = (l + r) / 2;
  long long inv = 0, invl = mrg(l, mid), invr = mrg(mid + 1, r);
  li.clear();
  ri.clear();
  for (int i = l; i <= mid; ++i) {
    li.push_back(a[i]);
  }
  for (int i = mid + 1; i <= r; ++i) {
    ri.push_back(a[i]);
  }
  int i = 0, j = 0, k = l;
  while (i < li.size() && j < ri.size()) {
    if (li[i] < ri[j]) {
      a[k] = li[i++];
    } else {
      inv += (mid - l - i + 1);
      a[k] = ri[j++];
    }
    ++k;
  }
  while (i < li.size()) {
    a[k++] = li[i++];
  }
  while (j < ri.size()) {
    a[k++] = ri[j++];
  }
  return invl + invr + inv;
}
int main() {
  cin >> n;
  cin >> second;
  for (int i = 0; i < n; ++i) {
    beg[second[i] - 'a'].push_back(i + 1);
    rev[second[i] - 'a'].push_back(n - i);
  }
  for (auto& v : rev) {
    sort(v.begin(), v.end());
  }
  for (int i = 0; i < AL; ++i) {
    for (int j = 0; j < beg[i].size(); ++j) {
      a[beg[i][j]] = rev[i][j];
    }
  }
  cout << mrg(1, n) << endl;
  return 0;
}
