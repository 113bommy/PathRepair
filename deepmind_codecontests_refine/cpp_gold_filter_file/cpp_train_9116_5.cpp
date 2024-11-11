#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 5000 + 3, MAX_M = 1000 + 3;
int n, m;
map<string, int> ID;
int type[MAX_N], leftOperand[MAX_N], rightOperand[MAX_N];
bool digit[MAX_N][MAX_M];
inline bool go(bool l, bool r, int type) {
  if (type == 0)
    return l & r;
  else if (type == 1)
    return l | r;
  else
    return l ^ r;
}
pair<int, int> solve(int d) {
  int cnt[2] = {0, 0};
  static bool nowDigit[MAX_N];
  for (int b = 0; b < 2; ++b) {
    nowDigit[n] = b;
    for (int i = 0; i < n; ++i)
      if (type[i] >= 0) {
        nowDigit[i] =
            go(nowDigit[leftOperand[i]], nowDigit[rightOperand[i]], type[i]);
        cnt[b] += nowDigit[i];
      } else {
        nowDigit[i] = digit[i][d];
      }
  }
  if (cnt[0] == cnt[1])
    return make_pair(0, 0);
  else if (cnt[0] < cnt[1])
    return make_pair(0, 1);
  else
    return make_pair(1, 0);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  string name, tmp, tmp1, oper, tmp2;
  ID["?"] = n;
  for (int i = 0; i < n; ++i) {
    cin >> name;
    ID[name] = i;
    cin >> tmp >> tmp1;
    if (tmp1[0] == '0' || tmp1[0] == '1') {
      type[i] = -1;
      for (int j = 0; j < m; ++j) digit[i][j] = tmp1[j] - '0';
    } else {
      cin >> oper >> tmp2;
      if (oper[0] == 'A')
        type[i] = 0;
      else if (oper[0] == 'O')
        type[i] = 1;
      else if (oper[0] == 'X')
        type[i] = 2;
      leftOperand[i] = ID[tmp1], rightOperand[i] = ID[tmp2];
    }
  }
  static char minAns[MAX_M], maxAns[MAX_M];
  for (int i = 0; i < m; ++i) {
    pair<int, int> pi = solve(i);
    minAns[i] = pi.first ? '1' : '0';
    maxAns[i] = pi.second ? '1' : '0';
  }
  minAns[m] = 0, maxAns[m] = 0;
  cout << minAns << endl << maxAns << endl;
  return 0;
}
