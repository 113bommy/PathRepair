#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, pair<int, int> > Hsh;
bool okz;
int result = -(1 << 29), a[666], b[666], c[666];
pair<int, int> coef_result;
void solve1(vector<int> grp) {
  int N = grp.size();
  int nr_pos = 1, i, j;
  for (i = 1; i <= N; ++i) nr_pos *= 3;
  for (i = 0; i < nr_pos; ++i) {
    int value = i;
    int v1 = 0, v2 = 0, v3 = 0;
    for (j = 0; j < N; ++j, value /= 3) {
      if (value % 3 == 0) v2 += b[grp[j]], v3 += c[grp[j]];
      if (value % 3 == 1) v1 += a[grp[j]], v3 += c[grp[j]];
      if (value % 3 == 2) v1 += a[grp[j]], v2 += b[grp[j]];
    }
    int cf1 = v1 - v2, cf2 = v1 - v3;
    if (Hsh.find(make_pair(cf1, cf2)) == Hsh.end())
      Hsh[make_pair(cf1, cf2)] = make_pair(v1, i);
    else
      Hsh[make_pair(cf1, cf2)] =
          max(Hsh[make_pair(cf1, cf2)], make_pair(v1, i));
  }
}
void solve2(vector<int> grp) {
  int N = grp.size();
  int nr_pos = 1, i, j;
  for (i = 1; i <= N; ++i) nr_pos *= 3;
  for (i = 0; i < nr_pos; ++i) {
    int value = i;
    int v1 = 0, v2 = 0, v3 = 0;
    for (j = 0; j < N; ++j, value /= 3) {
      if (value % 3 == 0) v2 += b[grp[j]], v3 += c[grp[j]];
      if (value % 3 == 1) v1 += a[grp[j]], v3 += c[grp[j]];
      if (value % 3 == 2) v1 += a[grp[j]], v2 += b[grp[j]];
    }
    int cf1 = -v1 + v2, cf2 = -v1 + v3;
    if (Hsh.find(make_pair(cf1, cf2)) == Hsh.end()) continue;
    pair<int, int> P = Hsh[make_pair(cf1, cf2)];
    if (P.first + v1 > result) {
      result = P.first + v1;
      coef_result = make_pair(P.second, i);
      okz = true;
    }
  }
}
void print_result(int value, int N) {
  for (int i = 1; i <= N; ++i, value /= 3) {
    if (value % 3 == 0) cout << "MW";
    if (value % 3 == 1) cout << "LW";
    if (value % 3 == 2) cout << "LM";
    cout << '\n';
  }
}
int main() {
  int n, i;
  cin >> n;
  for (i = 1; i <= n; ++i) cin >> a[i] >> b[i] >> c[i];
  if (n == 1) {
    if ((a[1] != 0 && b[1] != 0) || (a[1] != 0 && c[1] != 0) ||
        (b[1] != 0 && c[1] != 0)) {
      cout << "Impossible";
      return 0;
    } else {
      int nr = 0;
      if (a[1] == 0) cout << "L", ++nr;
      if (a[2] == 0) cout << "M", ++nr;
      if (a[3] == 0 && nr == 1) cout << "W";
      return 0;
    }
    return 0;
  }
  vector<int> first_group, second_group;
  for (i = 1; i <= n / 2; ++i) first_group.push_back(i);
  for (i = n / 2 + 1; i <= n; ++i) second_group.push_back(i);
  solve1(first_group);
  solve2(second_group);
  if (okz == false) {
    cout << "Impossible";
    ;
    return 0;
  }
  print_result(coef_result.first, n / 2);
  print_result(coef_result.second, n - n / 2);
  return 0;
}
