#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  if (n == 0) {
    cout << "-8\n";
    return 0;
  }
  vector<int> a;
  while (n) {
    if (n & 1)
      a.push_back(1);
    else
      a.push_back(0);
    n /= 2;
  }
  while (a.size() < 4) a.push_back(0);
  int last;
  for (int i = 0; i < 4; i++)
    if (a[i]) last = i;
  a[last] = 0;
  for (int i = last + 1; i < 4; i++) a[i] = 1;
  for (int i = 0; i < 4; i++) n += a[i] * (1 << i);
  cout << n << "\n";
  return 0;
}
