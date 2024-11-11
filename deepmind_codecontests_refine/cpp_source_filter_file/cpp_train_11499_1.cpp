#include <bits/stdc++.h>
using namespace std;
int n;
bool ok[6][6];
set<char> s1[6];
set<char> s2[6];
vector<int> v1[6], v2[6];
char col[105];
char num[105];
int hint[105];
int ans;
int main() {
  cin >> n;
  ans = n;
  for (int i = 1; i <= n; i++) {
    cin >> col[i] >> num[i];
    if (col[i] == 'R') {
      col[i] = 'A';
    } else if (col[i] == 'G') {
      col[i] = 'B';
    } else if (col[i] == 'B') {
      col[i] = 'C';
    } else if (col[i] == 'Y') {
      col[i] = 'D';
    } else {
      col[i] = 'E';
    }
    v1[col[i] - 'A' + 1].push_back(i);
    v2[num[i] - '0'].push_back(i);
  }
  for (int msk = 0; msk < (1 << n); msk++) {
    int t = msk;
    int pl = 0;
    int cnt = 0;
    for (int i = 1; i <= 5; i++) {
      s1[i].clear();
      s2[i].clear();
    }
    memset(hint, 0, sizeof(hint));
    while (t) {
      pl++;
      if (t % 2) {
        cnt++;
        if (pl <= 5) {
          for (int i = 0; i < v1[pl].size(); i++) {
            hint[v1[pl][i]]++;
            s1[pl].insert(num[v1[pl][i]]);
          }
        } else {
          for (int i = 0; i < v2[pl - 5].size(); i++) {
            hint[v2[pl - 5][i]]++;
            s2[pl - 5].insert(col[v2[pl - 5][i]]);
          }
        }
      }
      t /= 2;
    }
    set<pair<char, char> > S;
    for (int i = 1; i <= n; i++) {
      if (hint[i] == 2) {
        s1[col[i] - 'A' + 1].erase(num[i]);
        s2[num[i] - '0'].erase(col[i]);
      } else if (hint[i] == 0) {
        S.insert(make_pair(col[i], num[i]));
      }
    }
    bool flag = true;
    for (int i = 1; i <= 5; i++) {
      if (s1[i].size() > 1 || s2[i].size() > 1) {
        flag = false;
        break;
      }
    }
    if (S.size() > 1) {
      flag = false;
    }
    if (flag) {
      ans = min(ans, cnt);
    }
  }
  cout << ans;
  return 0;
}
