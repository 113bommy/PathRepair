#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y, id;
  bool operator<(const node &r) const { return x < r.x; }
} e[100005];
int ans[100005];
map<string, int> mp;
int main() {
  int a[6] = {0};
  mp["S"] = 0, mp["M"] = 1, mp["L"] = 2, mp["XL"] = 3, mp["XXL"] = 4,
  mp["XXXL"] = 5;
  string s, str, s1, res[6] = {"S", "M", "L", "XL", "XXL", "XXXL"};
  for (int i = 0; i < 6; i++) {
    cin >> a[i];
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> str;
    s = "", s1 = "";
    int m = str.size(), flag = 0;
    for (int k = 0; k < m; k++) {
      if (str[k] == ',') {
        flag = 1;
      } else if (!flag) {
        s += str[k];
      } else
        s1 += str[k];
    }
    if (!flag) {
      e[i].x = e[i].y = mp[s];
      ans[i] = e[i].x;
      a[e[i].x]--;
    } else {
      e[i].x = mp[s], e[i].y = mp[s1];
      if (e[i].x > e[i].y) swap(e[i].x, e[i].y);
    }
    e[i].id = i;
  }
  sort(e, e + n);
  for (int i = 0; i < n; i++) {
    if (e[i].x == e[i].y) continue;
    if (a[e[i].x] > 0)
      a[e[i].x]--, ans[e[i].id] = e[i].x;
    else
      a[e[i].y]--, ans[e[i].id] = e[i].y;
  }
  for (int i = 0; i < 6; i++) {
    if (a[i] < 0) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  for (int i = 0; i < n; i++) {
    cout << res[ans[i]] << endl;
  }
}
