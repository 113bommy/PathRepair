#include <bits/stdc++.h>
using namespace std;
const double pi =
    3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;
pair<int, pair<int, int>> t[30];
map<pair<int, int>, pair<int, string>> M;
int best;
string beststr;
int s[3], mx, mn;
void process(int cur, int end, int ind, string str);
void go(pair<int, pair<int, int>> p, int cur, const int &end, const int &ind,
        string str);
void process(int cur, int end, int ind, string str) {
  mx = max(s[0], max(s[1], s[2]));
  mn = min(s[0], min(s[1], s[2]));
  if (cur == end) {
    if (!ind) {
      pair<int, int> pom = make_pair(s[1] - s[0], s[2] - s[1]);
      if (M.find(pom) == M.end() || M[pom].first < mx + mn)
        M[pom] = make_pair(mn, str);
    } else {
      pair<int, int> pom = make_pair(s[0] - s[1], s[1] - s[2]);
      pair<int, string> found;
      if (M.find(pom) != M.end()) {
        found = M.find(pom)->second;
        if (found.first + mx > best) {
          best = found.first + mx;
          beststr = found.second + str;
        }
      }
    }
  } else
    go(make_pair(s[0], make_pair(s[1], s[2])), cur + 1, end, ind, str);
}
void go(pair<int, pair<int, int>> p, int cur, const int &end, const int &ind,
        string str) {
  if (cur > end) return;
  s[0] = p.first + t[cur].first;
  s[1] = p.second.first + t[cur].second.first;
  s[2] = p.second.second;
  process(cur, end, ind, str + '0');
  s[0] = p.first + t[cur].first;
  s[1] = p.second.first;
  s[2] = p.second.second + t[cur].second.second;
  process(cur, end, ind, str + '1');
  s[0] = p.first;
  s[1] = p.second.first + t[cur].second.first;
  s[2] = p.second.second + t[cur].second.second;
  process(cur, end, ind, str + '2');
}
int main() {
  best = -1e9;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < (n); ++i)
    scanf("%d%d%d", &t[i].first, &t[i].second.first, &t[i].second.second);
  if (n == 1) {
    if (t[0].first == t[0].second.first)
      printf("LM\n");
    else if (t[0].first == t[0].second.second)
      printf("LW\n");
    else if (t[0].second.first == t[0].second.second)
      printf("MW\n");
    else
      printf("Impossible\n");
    return 0;
  }
  go(make_pair(0, make_pair(0, 0)), 0, n / 2 - 1, 0, "");
  go(make_pair(0, make_pair(0, 0)), n / 2, n - 1, 1, "");
  if (best == -1e9)
    printf("Impossible\n");
  else {
    for (int i = 0; i < (n); ++i)
      if (beststr[i] == '0')
        printf("LM\n");
      else if (beststr[i] == '1')
        printf("LW\n");
      else
        printf("MW\n");
  }
  return 0;
}
