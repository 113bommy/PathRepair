#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int gotem[1 << 12];
int store[1 << 12][201];
int wu[12];
int stringToBinary(string s) {
  int answer = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') answer += 1 << i;
  }
  return answer;
}
int main() {
  if (fopen("FILENAME.in", "r")) {
    freopen("FILENAME.in", "r", stdin);
    freopen("FILENAME.out", "w", stdout);
  }
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> q;
  for (int i = 0; i < n; i++) {
    cin >> wu[i];
  }
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    gotem[stringToBinary(s)]++;
  }
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < (1 << n); j++) {
      int wuValue = 0;
      for (int k = 0; k < n; k++) {
        if ((i & (1 << k)) == (j & (1 << k))) {
          wuValue += wu[k];
        }
      }
      store[i][min(wuValue, 101)] += gotem[j];
    }
  }
  for (int i = 0; i < q; i++) {
    string s;
    int k;
    cin >> s >> k;
    int ans = 0;
    int intV = stringToBinary(s);
    for (int j = 0; j <= k; j++) {
      ans += store[intV][j];
    }
    cout << ans << '\n';
  }
}
