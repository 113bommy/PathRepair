#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 5;
struct part {
  int t_shirt1, t_shirt2, ind;
  part() {}
  part(int a, int b, int c) {
    t_shirt1 = a;
    t_shirt2 = b;
    ind = c;
  }
};
bool p;
int n, a[7], t1, t2;
string s, t_shirt1, t_shirt2, t_shirts1[maxN], t_shirts2[maxN], ans[maxN];
vector<part> parts;
int get_code(string t) {
  if (t == "S")
    return 0;
  else if (t == "M")
    return 1;
  else if (t == "L")
    return 2;
  else if (t == "XL")
    return 3;
  else if (t == "XXL")
    return 4;
  else if (t == "XXXL")
    return 5;
  else
    return -1;
}
bool cmp_parts(part x, part y) {
  if (x.t_shirt1 != y.t_shirt1)
    return x.t_shirt1 < y.t_shirt1;
  else
    return x.t_shirt2 < y.t_shirt2;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (int i = 0; i < 6; i++) {
    cin >> a[i];
  }
  cin >> n;
  for (int i = 0; i < n; i++) {
    p = false;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ',') {
        t_shirt1 = s.substr(0, i);
        t_shirt2 = s.substr(i + 1);
        p = true;
        break;
      }
    }
    if (!p) {
      t_shirt1 = s;
      t_shirt2 = "1";
    }
    t_shirts1[i] = t_shirt1;
    t_shirts2[i] = t_shirt2;
    t1 = get_code(t_shirt1);
    t2 = get_code(t_shirt2);
    parts.push_back(part(t1, t2, i));
  }
  sort(parts.begin(), parts.end(), cmp_parts);
  for (int i = 0; i < n; i++) {
    if (a[parts[i].t_shirt1] != 0) {
      ans[parts[i].ind] = t_shirts1[parts[i].ind];
      a[parts[i].t_shirt1]--;
    } else {
      if (t_shirts2[parts[i].ind] == "1" || a[parts[i].t_shirt2] == 0) {
        cout << "NO" << '\n';
        return 0;
      } else {
        ans[parts[i].ind] = t_shirts2[parts[i].ind];
        a[parts[i].t_shirt2]--;
      }
    }
  }
  cout << "YES" << '\n';
  for (int i = 0; i < n; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}
