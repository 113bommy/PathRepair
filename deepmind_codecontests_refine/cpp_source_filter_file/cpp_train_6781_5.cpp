#include <bits/stdc++.h>
using namespace std;
int scan() {
  bool minus = false;
  int result = 0;
  char ch;
  ch = getchar();
  while (true) {
    if (ch == '-') break;
    if (ch >= '0' && ch <= '9') break;
    ch = getchar();
  }
  if (ch == '-')
    minus = true;
  else
    result = ch - '0';
  while (true) {
    ch = getchar();
    if (ch < '0' || ch > '9') break;
    result = result * 10 + (ch - '0');
  }
  if (minus)
    return -result;
  else
    return result;
}
int n, m;
vector<int> vec[100011];
void seive() {
  vec[1].push_back(1);
  for (int i = 2; i <= 100011; i++) {
    vec[i].push_back(1);
    for (int j = i; j <= 100011; j += i) {
      vec[j].push_back(i);
    }
  }
}
int pos[100011];
int main() {
  int t;
  seive();
  t = scan();
  int id = 1;
  while (t--) {
    int x, y;
    x = scan();
    y = scan();
    int ans = 0;
    for (int i = 0; i < vec[x].size(); i++) {
      int v = vec[x][i];
      if (pos[v] < i - y) ans++;
      pos[v] = id;
    }
    id++;
    cout << ans + 1 << endl;
  }
  return 0;
}
