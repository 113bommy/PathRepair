#include <bits/stdc++.h>
using namespace std;
int n, k, j, num;
pair<int, int> a[110];
set<int> s;
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> num;
    a[i] = {num, i};
  }
  sort(a, a + n);
  while (k - a[j].first >= 0 && j < n) {
    s.insert(a[j].second);
    k -= a[j].first;
    j++;
  }
  cout << s.size() << "\n";
  for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
    cout << *it + 1 << " ";
  }
  return 0;
}
