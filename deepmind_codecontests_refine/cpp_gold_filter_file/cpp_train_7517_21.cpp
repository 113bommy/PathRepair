#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;
namespace std {
bool operator<(const complex<double>& a, const complex<double>& b) {
  return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
}
}  // namespace std
int n = 8, m;
char s[123][123];
vector<pair<int, int> > st;
bool taken(int i, int j, int t) {
  if (i < 0 || i >= n || j < 0 || j >= n) return true;
  for (int k = (0); k < (int)(st.size()); k++) {
    int r = st[k].first;
    int c = st[k].second;
    if (i == r + t && j == c) return true;
    if (i == r + t - 1 && j == c) return true;
  }
  return false;
}
int main() {
  for (int i = (0); i < (int)(n); i++) {
    scanf("%s", s[i]);
    for (int j = (0); j < (int)(n); j++) {
      if (s[i][j] == 'S') st.push_back(make_pair(i, j));
    }
  }
  queue<pair<pair<int, int>, int> > q;
  q.push(make_pair(make_pair(7, 0), 0));
  while (!q.empty()) {
    pair<pair<int, int>, int> a = q.front();
    q.pop();
    for (int k = (0); k < (int)(9); k++) {
      int r = a.first.first + k / 3 - 1;
      int c = a.first.second + k % 3 - 1;
      int t = a.second + 1;
      if (r == 0 && c == 7) {
        printf("WIN\n");
        return 0;
      }
      if (!taken(r, c, t)) {
        q.push(make_pair(make_pair(r, c), t));
      }
    }
  }
  printf("LOSE\n");
  return 0;
}
