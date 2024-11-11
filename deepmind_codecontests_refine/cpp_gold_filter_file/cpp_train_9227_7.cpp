#include <bits/stdc++.h>
using namespace std;
ifstream fin("Sisend.txt");
long long n, a, b, c;
pair<long long, int> pr[300005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cerr.tie(0);
  cin >> n >> a >> b;
  for (int(i) = (0); ((i)) < ((n)); ((i))++) {
    cin >> c;
    pr[i] = {c, i + 1};
  }
  sort(pr, pr + n);
  reverse(pr, pr + n);
  int l = 0, r = 0;
  while (l < n and pr[l].first * (l + 1) < a) l++;
  if (l == n) {
    cout << "No";
    return 0;
  }
  r = l + 1;
  while (r < n and pr[r].first * (r - l) < b) r++;
  if (pr[r].first * (r - l) >= b) {
    cout << "Yes" << endl;
    cout << l + 1 << " " << r - l << endl;
    for (int(i) = (0); ((i)) < ((l + 1)); ((i))++) cout << pr[i].second << " ";
    cout << endl;
    for (int i = l + 1; i <= r; i++) cout << pr[i].second << " ";
    cout << endl;
    return 0;
  }
  l = 0;
  while (l < n and pr[l].first * (l + 1) < b) l++;
  if (l == n) {
    cout << "No";
    return 0;
  }
  r = l + 1;
  while (r < n and pr[r].first * (r - l) < a) r++;
  if (pr[r].first * (r - l) >= a) {
    cout << "Yes" << endl;
    cout << r - l << " " << l + 1 << endl;
    for (int i = l + 1; i <= r; i++) cout << pr[i].second << " ";
    cout << endl;
    for (int(i) = (0); ((i)) < ((l + 1)); ((i))++) cout << pr[i].second << " ";
    cout << endl;
    return 0;
  }
  cout << "No";
}
