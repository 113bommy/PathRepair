#include <bits/stdc++.h>
using namespace std;
int bin(int l, int r) {
  int search = -1;
  long long isg = l;
  while (l <= r) {
    int mid = (l + r) / 2;
    cout << "? " << isg << " " << mid << endl;
    char a;
    cin >> a;
    if (a == 'x') {
      search = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return search;
}
void bibpo() {
  cout << "? " << 0 << " " << 1 << endl;
  char a;
  cin >> a;
  if (a == 'x') {
    cout << "! " << 1 << endl;
    return;
  } else if (a == 'e') {
    return;
  }
  int f = 1, s = 2;
  while (a != 'x') {
    cout << "? " << f << " " << s << endl;
    cin >> a;
    if (a != 'x') {
      f = s;
      s = f * 2;
    }
  }
  long long ans = bin(f, s);
  cout << "! " << ans << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  while (1) {
    string s;
    cin >> s;
    if (s == "start") {
      bibpo();
    } else {
      break;
    }
  }
  return 0;
}
