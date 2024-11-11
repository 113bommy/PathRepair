#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
  ios::sync_with_stdio(false);
  int n, x;
  cin >> n >> x;
  bool has_x = false;
  deque<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] == x) {
      has_x = true;
    }
  }
  int ans = 0;
  if (!has_x) {
    a.push_back(x);
    ans++;
  }
  sort(a.begin(), a.end());
  int size = a.size();
  int median = (size + 1) / 2;
  int pos = 0;
  int mdist = INT_MAX;
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] == x) {
      if (abs(i + 1 - median) < mdist) {
        mdist = abs(i + 1 - median);
        pos = i + 1;
      }
    }
  }
  while (median != pos) {
    ans++;
    if (median < pos) {
      size++;
      median = (size + 1) / 2;
    } else if (median > pos) {
      size++;
      pos++;
      median = (size + 1) / 2;
    }
  }
  cout << ans << endl;
  return 0;
}
