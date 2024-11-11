#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
int inp[150005];
int ind[150005];
set<pair<int, int> > coll;
int main() {
  int n, ans = 0;
  cin >> n;
  for (int i = 1; i < n + 1; i++) cin >> inp[i];
  int cnt = 0;
  for (int i = 1; i < n + 1; i++) {
    if (!(i & 1)) {
      if (!(inp[i] > inp[i - 1] && (i == n || inp[i] > inp[i + 1]))) {
        ind[cnt] = i;
        cnt++;
      }
    } else {
      if (!((i == n || inp[i] < inp[i + 1]) &&
            (i == 1 || inp[i] < inp[i - 1]))) {
        ind[cnt] = i;
        cnt++;
      }
    }
  }
  if (cnt > 6) {
    cout << "0";
    return 0;
  }
  int k, id;
  for (int i = 0; i < cnt; i++) {
    int in = 1;
    while (in <= n) {
      if (in == ind[i]) {
        in++;
        continue;
      }
      if (abs(in - ind[i]) == 1)
        swap(inp[in], inp[ind[i]]);
      else if (!(in & 1) && (inp[ind[i]] > inp[in - 1] &&
                             (in == n || inp[ind[i]] > inp[in + 1])))
        swap(inp[in], inp[ind[i]]);
      else if ((in & 1) && ((in == n || inp[ind[i]] < inp[in + 1]) &&
                            (in == 1 || inp[ind[i]] < inp[in - 1])))
        swap(inp[in], inp[ind[i]]);
      else {
        in++;
        continue;
      }
      if (coll.find({in, ind[i]}) != coll.end() ||
          coll.find({ind[i], in}) != coll.end()) {
        swap(inp[in], inp[ind[i]]);
        in++;
        continue;
      }
      coll.insert({in, ind[i]});
      for (k = 0; k < cnt; k++) {
        id = ind[k];
        if (!(id & 1)) {
          if (!(inp[id] > inp[id - 1] && (id == n || inp[id] > inp[id + 1]))) {
            break;
          }
        } else {
          if (!((id == n || inp[id] < inp[id + 1]) &&
                (id == 1 || inp[id] < inp[id - 1]))) {
            break;
          }
        }
      }
      if (k == cnt) ans++;
      swap(inp[in], inp[ind[i]]);
      in++;
    }
  }
  cout << ans << " ";
  return 0;
}
