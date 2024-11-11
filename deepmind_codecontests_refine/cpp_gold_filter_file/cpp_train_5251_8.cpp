#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, mn, mx;
  cin >> n >> m >> mn >> mx;
  set<int> temp;
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    temp.insert(x);
  }
  if (*temp.begin() < mn or *temp.rbegin() > mx) {
    cout << "Incorrect" << endl;
    return 0;
  }
  int off = 0;
  if (*temp.begin() != mn) off++;
  if (*temp.rbegin() != mx) off++;
  if (n - m >= off) {
    cout << "Correct" << endl;
  } else {
    cout << "Incorrect" << endl;
  }
  return 0;
}
