#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
void mysol() {
  long long a, b;
  cin >> a >> b;
  long long prob = 6 - max(a, b) + 1;
  if (prob % 6 == 0)
    cout << prob / 6 << '/' << 6 / 6;
  else if (prob % 2 == 0)
    cout << prob / 2 << '/' << 6 / 2;
  else if (prob % 3 == 0)
    cout << prob / 3 << '/' << 6 / 3;
  else
    cout << prob << '/' << 6;
}
int32_t main() {
  fast();
  { mysol(); }
  return 0;
}
