#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  multimap<int, int> c;
  multimap<int, int>::iterator ci;
  multimap<int, int> a;
  multimap<int, int>::iterator ai;
  int n, k;
  cin >> n;
  int *b = new int(n + 2);
  int *d = new int(n + 2);
  for (int i = 0; i < n; i++) {
    cin >> k;
    a.insert(pair<int, int>(k, i));
  }
  ai = a.begin();
  for (int i = 0; i < n; i++) {
    d[n - i - 1] = ai->first;
    ai++;
  }
  for (int i = 0; i < n; i++) {
    cin >> k;
    c.insert(pair<int, int>(k, i));
  }
  ci = c.begin();
  for (int i = 0; i < n; i++) {
    b[ci->second] = i;
    ci++;
  }
  for (int i = 0; i < n; i++) {
    if (i != 0) cout << ' ';
    cout << d[b[i]];
  }
  cout << "\n";
  cout.flush();
  return 0;
}
