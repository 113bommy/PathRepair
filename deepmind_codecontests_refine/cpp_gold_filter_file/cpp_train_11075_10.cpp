#include <bits/stdc++.h>
using namespace std;
int R, C;
void findNext(int &ii, int &jj, pair<int, int> &di, int &num) {
  if (di.first < 0 && di.second < 0) {
    num = min(ii - 1, jj - 1);
  } else if (di.first < 0 && di.second > 0) {
    num = min(ii - 1, C - jj);
  } else if (di.first > 0 && di.second > 0) {
    num = min(R - ii, C - jj);
  } else {
    num = min(R - ii, jj - 1);
  }
  ii = ii + num * di.first;
  jj = jj + num * di.second;
  if (ii <= 0)
    ii += R;
  else if (ii > R)
    ii -= R;
  if (jj <= 0)
    jj += C;
  else if (jj > C)
    jj -= C;
  if ((ii == 1 && jj == 1 && di.first == -1 && di.second == -1) ||
      (ii == 1 && jj == C && di.first == -1 && di.second == 1) ||
      (ii == R && jj == 1 && di.first == 1 && di.second == -1) ||
      (ii == R && jj == C && di.first == 1 && di.second == 1)) {
    di.first *= -1;
    di.second *= -1;
  } else if (ii == 1 || ii == R) {
    di.first *= -1;
  } else {
    di.second *= -1;
  }
}
int main() {
  cin >> R >> C;
  int si, sj;
  pair<int, int> di;
  string in;
  cin >> si >> sj >> in;
  if (in == "UL")
    di = pair<int, int>(-1, -1);
  else if (in == "UR")
    di = pair<int, int>(-1, 1);
  else if (in == "DR")
    di = pair<int, int>(1, 1);
  else
    di = pair<int, int>(1, -1);
  set<pair<int, int> > S;
  for (int i = ((si + sj) % 2) + 1; i <= R; i += 2) {
    S.insert(pair<int, int>(i, 1));
    if (C % 2)
      S.insert(pair<int, int>(i, C));
    else if (i + 1 <= R)
      S.insert(pair<int, int>(i + 1, C));
  }
  for (int i = ((si + sj) % 2) + 1; i <= C; i += 2) {
    S.insert(pair<int, int>(1, i));
    if (R % 2)
      S.insert(pair<int, int>(R, i));
    else if (i + 1 <= C)
      S.insert(pair<int, int>(R, i + 1));
  }
  long long ans = 0;
  if (S.find(pair<int, int>(si, sj)) != S.end()) {
    ans++;
    S.erase(pair<int, int>(si, sj));
  }
  int sz = S.size();
  for (int i = 0; i < sz * 8; i++) {
    if (S.empty()) {
      cout << ans << endl;
      return 0;
    }
    int num = 0;
    findNext(si, sj, di, num);
    ans += num;
    S.erase(pair<int, int>(si, sj));
  }
  cout << -1 << endl;
  return 0;
}
