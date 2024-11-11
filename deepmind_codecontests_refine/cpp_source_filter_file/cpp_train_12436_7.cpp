#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, w;
vector<int> vec, vec2;
vector<int> aux, aux2;
int lps[(int)(1e6 + 10)];
void solve() {
  int i = 1, len = 0;
  while (i < int(aux.size())) {
    if (aux[i] == aux2[len]) {
      lps[i] = ++len;
      i++;
    } else {
      if (len > 0)
        len = lps[len - 1];
      else
        i++;
    }
  }
  int j = 0;
  i = 0;
  int ans = 0;
  while (i < int(aux.size())) {
    if (aux[i] == aux2[j]) {
      i++, j++;
    } else {
      if (j > 0)
        j = lps[j - 1];
      else
        i++;
    }
    if (j == int(aux2.size())) {
      j = lps[j - 1];
      ans++;
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> w;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    vec.push_back(a);
  }
  for (int i = 0; i < w; i++) {
    int a;
    cin >> a;
    vec2.push_back(a);
  }
  if (w == 1) {
    cout << n << "\n";
    return 0;
  } else if (w > n) {
    cout << 0 << "\n";
    return 0;
  }
  for (int i = 0; i < int(vec.size()) - 1; i++) {
    aux.push_back(vec[i + 1] - vec[i]);
  }
  for (int i = 0; i < int(vec2.size()) - 1; i++) {
    aux2.push_back(vec2[i + 1] - vec2[i]);
  }
  solve();
  return 0;
}
