#include <bits/stdc++.h>
using namespace std;
const int N = 305;
int n;
string w[N];
bool b[N][N];
int kmp[N];
void makekmp(int idx) {
  kmp[idx] = 0;
  int i = idx + 1, j = 0;
  while (i < n) {
    if (b[i][idx + j])
      kmp[i++] = ++j;
    else if (j == 0)
      kmp[i++] = 0;
    else
      j = kmp[j - 1];
  }
}
vector<int> kmpfind(int idx, int len) {
  int i = idx, j = 0;
  vector<int> v;
  while (i < n) {
    if (b[i][idx + j]) i++, j++;
    if (j == len) {
      v.push_back(i - j);
      j = 0;
    } else if (i < n && !b[i][idx + j]) {
      if (j == 0)
        i++;
      else
        j = kmp[j - 1];
    }
  }
  return v;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  int tot = n - 1;
  for (int i = (0); i < (n); i++) {
    cin >> w[i];
    tot += w[i].length();
  }
  for (int i = (0); i < (n); i++)
    for (int j = (i); j < (n); j++) {
      b[i][j] = b[j][i] = (w[i] == w[j]);
    }
  int ans = tot;
  for (int i = (0); i < (n); i++) {
    makekmp(i);
    int sum = 0;
    for (int len = 1; i + len <= n; len++) {
      sum += w[i + len - 1].length();
      int k = ((int)(kmpfind(i, len)).size());
      if (k >= 2) {
        ans = min(ans, tot + k - k * sum);
      }
    }
  }
  cout << ans << endl;
}
