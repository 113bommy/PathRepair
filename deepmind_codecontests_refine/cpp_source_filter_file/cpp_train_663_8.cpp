#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
template <class T>
vector<T> takeInput(int n) {
  vector<T> list;
  T a;
  int i;
  for (i = 0; i < n; i++) {
    cin >> a;
    list.push_back(a);
  }
  return list;
}
long long ncr[305][305] = {0};
void gen_ncr(int n) {
  int i, j;
  for (i = 0; i <= n; i++) ncr[i][0] = 1;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) ncr[i][j] = ncr[i - 1][j] + ncr[i - 1][j - 1];
}
double dis(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
string s;
int n;
int dp[2600][2600];
int par[2600][2600];
const int match = 0;
const int leftP = 1;
const int rightM = 2;
int memo(int left, int right) {
  if (left > right) return 0;
  if (left == right) return 1;
  if (dp[left][right] != -1) return dp[left][right];
  int res = 0;
  if (s[left] == s[right]) {
    res = memo(left + 1, right - 1) + 2;
    par[left][right] = match;
    return dp[left][right] = res;
  }
  res = memo(left + 1, right);
  par[left][right] = leftP;
  int k = memo(left, right - 1);
  if (k > res) {
    res = k;
    par[left][right] = rightM;
  }
  return dp[left][right] = res;
}
int main() {
  int test, cases = 1;
  cin >> s;
  if (s.size() >= 26 * 99 + 1) {
    int fre[26] = {0};
    for (int i = 0; i < s.size(); i++) {
      fre[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
      if (fre[i] >= 100) {
        int cnt = 100;
        while (cnt--) cout << (i + 'a');
        cout << endl;
        return 0;
      }
    }
  }
  n = s.size();
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++) dp[i][j] = -1;
  int kk = memo(0, n - 1);
  int left, right;
  left = 0;
  right = n - 1;
  string res = "";
  while (left < right) {
    if (par[left][right] == match) {
      res += s[left];
      left++;
      right--;
    } else if (par[left][right] == leftP) {
      left++;
    } else {
      right--;
    }
    if (res.size() == 50) break;
  }
  if (left == right) {
    string rev = res;
    reverse(rev.begin(), rev.end());
    if (res.size() < 50)
      res = res + s[left] + rev;
    else
      res = res + rev;
  } else {
    string rev = res;
    reverse(rev.begin(), rev.end());
    res = res + rev;
  }
  cout << res << endl;
  return 0;
}
