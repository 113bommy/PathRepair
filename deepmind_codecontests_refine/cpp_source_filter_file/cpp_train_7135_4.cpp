#include <bits/stdc++.h>
using namespace std;
long long pref[200010], A[200010], dp[200010], sumi[200010];
vector<long long> pts;
struct line {
  long long m, c;
  line(long long a, long long b) {
    m = a;
    c = b;
  }
  line() {
    m = 0;
    c = 0;
  }
};
vector<line> ln, ch;
bool mycomp(line& A, line& B) { return (A.m - B.m) > 1e-12; }
bool checkmid(line A, line B, line C) {
  return ((B.c - A.c) * (A.m - C.m) > (C.c - A.c) * (A.m - B.m));
}
long long findint(line A, line B) {
  return (long long)((B.c - A.c + A.m - B.m - 1) / (A.m - B.m));
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> A[i];
    pref[i] = pref[i - 1] + i * A[i];
    sumi[i] = sumi[i - 1] + A[i];
  }
  for (int i = 0; i < n; i++) {
    dp[i + 1] = -1;
    int pt = ch.size();
    while (pt > 1 &&
           checkmid(ch[pt - 2], ch[pt - 1], line(i, i * sumi[i] - pref[i]))) {
      pts.pop_back();
      ch.pop_back();
      pt--;
    }
    if (i)
      pts.push_back(findint(line(i, i * sumi[i] - pref[i]), ch[pt - 1]));
    else
      pts.push_back(-1 * 1e12);
    ch.push_back(line(i, i * sumi[i] - pref[i]));
    pt++;
    int x =
        upper_bound(pts.begin(), pts.end(), -1 * sumi[i + 1]) - pts.begin() - 1;
    dp[i + 1] = pref[i + 1] + (-1 * sumi[i + 1] * ch[x].m + ch[x].c);
  }
  long long maxi = 0;
  for (int i = 1; i <= n; i++) maxi = max(dp[i], maxi);
  cout << maxi << '\n';
}
