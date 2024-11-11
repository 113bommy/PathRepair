#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ans1 = 0, ans2 = 0;
  string a, b;
  cin >> a >> b;
  for (int i = 0; i < a.size() * b.size(); i++) {
    if (a[i % a.size()] == 'R' && b[i % b.size()] == 'S') ans2++;
    if (a[i % a.size()] == 'P' && b[i % b.size()] == 'R') ans2++;
    if (a[i % a.size()] == 'S' && b[i % b.size()] == 'P') ans2++;
    if (a[i % a.size()] == 'S' && b[i % b.size()] == 'R') ans1++;
    if (a[i % a.size()] == 'R' && b[i % b.size()] == 'P') ans1++;
    if (a[i % a.size()] == 'P' && b[i % b.size()] == 'S') ans1++;
  }
  ans1 *= n / (a.size() * b.size());
  ans2 *= n / (a.size() * b.size());
  n %= (a.size() * b.size());
  for (int i = 0; i < n; i++) {
    if (a[i % a.size()] == 'R' && b[i % b.size()] == 'S') ans2++;
    if (a[i % a.size()] == 'P' && b[i % b.size()] == 'R') ans2++;
    if (a[i % a.size()] == 'S' && b[i % b.size()] == 'P') ans2++;
    if (a[i % a.size()] == 'S' && b[i % b.size()] == 'R') ans1++;
    if (a[i % a.size()] == 'R' && b[i % b.size()] == 'P') ans1++;
    if (a[i % a.size()] == 'P' && b[i % b.size()] == 'S') ans1++;
  }
  cout << ans1 << " " << ans2 << endl;
  return 0;
}
