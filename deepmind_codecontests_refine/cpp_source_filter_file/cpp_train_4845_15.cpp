#include <bits/stdc++.h>
long long int mod = 1000000000 + 7;
long long int inf = (long long int)(5e18);
using namespace std;
mt19937 unlucko(chrono::steady_clock::now().time_since_epoch().count());
map<string, string> mp;
map<string, bool> used;
void preproc() {
  for (int i = 1989; i < 20000; i++) {
    string cur = to_string(i);
    for (int j = cur.length() - 1; j >= 0; j--) {
      string temp = cur.substr(j, cur.length() - j);
      if (!used[temp]) {
        mp[temp] = cur;
        used[temp] = true;
        break;
      }
    }
  }
}
int getraz(int x) {
  int ans = 1;
  for (int i = 0; i < x; i++) ans *= 10;
  return ans;
}
int getr(int x) {
  int cur = 1;
  while (2 * cur < x) {
    x += cur;
    cur *= 10;
  }
  x /= 10000;
  x *= 10000;
  x += 3198;
  return x;
}
int to_num(string x) {
  int ans = 0;
  for (int i = 0; i < x.length(); i++) {
    ans *= 10;
    ans += x[i] - '0';
  }
  return ans;
}
int main() {
  iostream::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  preproc();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      char x;
      cin >> x;
    }
    string x;
    cin >> x;
    if (used[x]) {
      cout << mp[x] << "\n";
    } else {
      int raz = getraz(x.length() - 1);
      int r = getr(raz);
      int xx = to_num(x);
      if (xx <= r) {
        cout << 1 << x << "\n";
      } else {
        cout << x << "\n";
      }
    }
  }
}
