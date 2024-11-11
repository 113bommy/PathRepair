#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5;
string t, p;
int a[MAX];
bool isOk(int delim) {
  string temp = t;
  for (int i = 0; i <= delim; i++) {
    temp[a[i]] = 0;
  }
  int k = 0;
  for (int i = 0; i < temp.length(); i++) {
    if (k < p.length() && temp[i] == p[k]) {
      k++;
    }
  }
  return k == p.length();
}
void solve() {
  cin >> t >> p;
  for (int i = 0; i < t.length(); i++) {
    cin >> a[i];
    a[i]--;
  }
  int l = 0;
  int r = t.length() - 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (isOk(mid)) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  if (isOk(r)) {
    cout << r + 1;
  } else {
    cout << 0;
  }
}
int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
