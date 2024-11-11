#include <bits/stdc++.h>
using namespace std;
string arr[50];
int cmp(string a, string b) {
  int bIDX = 0, cnt = 0;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == b[bIDX]) {
      bIDX++;
      cnt++;
      if (bIDX == b.length()) {
        break;
      }
    }
  }
  return (a.length() - 2 * bIDX + b.length());
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long int saved_int = 1;
  for (int i = 0; i < 50; i++) {
    arr[i] = to_string(saved_int);
    saved_int *= 2LL;
  }
  int t;
  cin >> t;
  while (t--) {
    string n;
    cin >> n;
    int mx = cmp(n, arr[0]);
    for (int i = 1; i < 50; i++) {
      mx = min(mx, cmp(n, arr[i]));
    }
    cout << mx << '\n';
  }
  return 0;
}
