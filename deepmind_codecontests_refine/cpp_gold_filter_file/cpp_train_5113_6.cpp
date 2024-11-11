#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, s;
  scanf("%d%d", &n, &s);
  s--;
  vector<int> a(n), b(n);
  for (auto& el : a) cin >> el;
  for (auto& el : b) cin >> el;
  if (!a[0]) {
    cout << "NO";
    return 0;
  }
  if (a[s]) {
    cout << "YES";
    return 0;
  }
  if (b[s]) {
    for (int ind = s + 1; ind < n; ind++)
      if (a[ind] && b[ind]) {
        cout << "YES";
        return 0;
      }
  }
  cout << "NO";
  return 0;
}
