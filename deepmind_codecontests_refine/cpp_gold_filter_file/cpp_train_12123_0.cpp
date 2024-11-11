#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000000000")
using namespace std;
int n, arr[3501], m, tmp[3501], uni[3501], gr[3501], cur;
string st;
vector<pair<int, int> > ans;
int getu(int x) {
  if (x == uni[x]) return x;
  return uni[x] = getu(uni[x]);
}
void upd(int x, int y) {
  int a = getu(x), b = getu(y);
  if (a == b) return;
  uni[b] = a;
  cur++;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) uni[i] = i, gr[i] = i;
  for (int i = 0; i < n; i++) cin >> arr[i], tmp[i] = arr[i];
  cin >> m;
  for (int i = 0; i < n; i++)
    if (tmp[i] != 1 + i) {
      for (int j = i + 1; j < n; j++)
        if (tmp[j] == i + 1) {
          upd(i, j);
          swap(tmp[i], tmp[j]);
          break;
        }
    }
  if (m == cur) {
    cout << 0 << endl;
    return 0;
  }
  if (m < cur) {
    for (int i = 0; i < n; i++) uni[i] = getu(i);
    int ii = 0, dif = cur - m;
    cout << dif << endl;
    while (dif) {
      for (int i = 0; i < n; i++) uni[i] = i;
      for (int i = 0; i < n; i++) uni[getu(i)] = getu(arr[i] - 1);
      while (arr[ii] == ii + 1) ii++;
      int x = getu(ii);
      for (int j = ii + 1; j < n; j++)
        if (x == getu(j)) {
          cout << ii + 1 << ' ' << j + 1 << ' ';
          swap(arr[ii], arr[j]);
          dif--;
          break;
        }
    }
    return 0;
  } else {
    int dif = m - cur;
    for (int i = 0; i < n; i++) {
      int x = getu(i);
      for (int j = i + 1; j < n; j++)
        if (x != getu(j)) {
          upd(i, j);
          ans.push_back(make_pair(i + 1, j + 1));
          dif--;
          if (dif == 0) break;
        }
      if (dif == 0) break;
    }
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i].first << ' ' << ans[i].second << ' ';
  return 0;
}
