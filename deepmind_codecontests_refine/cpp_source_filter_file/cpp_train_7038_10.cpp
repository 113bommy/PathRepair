#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long double pi = acos(-1);
const int MOD = 1e9 + 7;
const long long int LINF = 0x3f3f3f3f3f3f3f3f;
int n, a, b, k, f;
map<string, int> trad;
int sum[105][105];
int v[100005];
int aux;
int getid(string &s) {
  if (trad.count(s))
    return trad[s];
  else
    return trad[s] = aux++;
}
int main() {
  ios::sync_with_stdio(false);
  ;
  cin >> n >> a >> b >> k >> f;
  int last = -1;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    string s1, s2;
    cin >> s1 >> s2;
    int id1 = getid(s1);
    int id2 = getid(s2);
    if (last == id1)
      sum[id1][id2] += b;
    else
      sum[id1][id2] += a;
    last = id2;
    sum[id2][id1] = sum[id1][id2];
  }
  int cont = 0;
  for (int i = 0; i < aux; i++) {
    for (int j = i + 1; j < aux; j++) {
      v[cont++] = sum[i][j];
      ans += sum[i][j];
    }
  }
  sort(v, v + cont);
  reverse(v, v + cont);
  for (int i = 0; i < k; i++) {
    if (v[i] > f) {
      ans -= v[i];
      ans += f;
    }
  }
  cout << ans << "\n";
  return 0;
}
