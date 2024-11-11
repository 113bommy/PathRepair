#include <bits/stdc++.h>
int dx[] = {0, 1, -1, 0, 1, -1, 1, -1, -2, 2, 0, 0},
    dy[] = {1, 0, 0, -1, -1, 1, 1, -1, 0, 0, -2, 2};
using namespace std;
int v[1000];
map<long long, long long> M[1000];
int main() {
  for (char c = 'a'; c <= 'z'; c++) {
    cin >> v[c];
  }
  string str;
  cin >> str;
  long long Asum[100005];
  Asum[0] = v[str[0]];
  for (int i = 1; i < str.size(); i++) {
    Asum[i] = Asum[i - 1] + v[str[i]];
  }
  long long ans = 0;
  for (int i = 0; i < str.size(); i++) {
    ans += M[str[i]][Asum[i] - v[str[i]]];
    M[str[i]][Asum[i]]++;
  }
  cout << ans << endl;
}
