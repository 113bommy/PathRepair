#include <bits/stdc++.h>
using namespace std;
int a[10][50];
int m;
int c[10];
int numWrong[10];
map<vector<int>, int> M;
long long res = 0;
void Find(int limit, int pos, string cur, bool isCheck) {
  int maxNumWrong = 0;
  for (int i = 1; i <= m; i++)
    if (numWrong[i] > c[i]) return;
  if (pos == limit) {
    vector<int> cur;
    for (int i = 1; i <= m; i++)
      if (isCheck)
        cur.push_back(c[i] - numWrong[i]);
      else
        cur.push_back(numWrong[i]);
    if (isCheck) {
      res += M[cur];
    } else {
      M[cur]++;
    }
    return;
  }
  for (int val = 0; val <= 1; val++) {
    for (int i = 1; i <= m; i++) {
      if (a[i][pos] == val) numWrong[i]++;
    }
    Find(limit, pos + 1, cur + (char)(val + '0'), isCheck);
    for (int i = 1; i <= m; i++) {
      if (a[i][pos] == val) numWrong[i]--;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < s.size(); j++) {
      a[i][j] = (int)(s[j] - '0');
    }
    cin >> c[i];
  }
  int mid = n / 2;
  Find(mid, 0, "", false);
  for (int i = 1; i <= m; i++) numWrong[i] = 0;
  Find(n, mid, "", true);
  cout << res;
}
