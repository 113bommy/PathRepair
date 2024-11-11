#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000;
const int INF = 0x7FFFFFFF;
const double eps = 1e-10;
const double pi = acos(-1.0);
int n;
string st;
vector<int> num1, num2;
int u[20], v[20], U[20], V[20];
int calc(int x, int y) {
  for (int i = 0; i <= 9; i++) {
    U[i] = u[i];
    V[i] = v[i];
  }
  if (u[x] == 0 || v[y] == 0) return 0;
  --U[x];
  --V[y];
  int ret = 1;
  for (int i = 0; i <= 9; i++)
    if (U[i] > 0 && V[9 - i] > 0) {
      int tmp = min(U[i], V[9 - i]);
      ret += tmp;
      U[i] -= tmp;
      V[9 - i] -= tmp;
    }
  return ret;
}
int main() {
  cin >> st;
  int n = st.size();
  memset(u, 0, sizeof(u));
  for (int i = 0; i < n; i++) ++u[st[i] - '0'];
  num1.clear();
  num2.clear();
  for (int i = 0; i <= 9; i++) v[i] = u[i];
  int delta = v[0] - v[9];
  for (int i = 1; i <= delta; i++) {
    num1.push_back(0);
    num2.push_back(0);
  }
  if (delta > 0) {
    u[0] -= delta;
    v[0] -= delta;
  }
  int ret = 0, now = 1;
  for (int i = 1; i <= 9; i++)
    if (calc(i, 10 - i) > ret) {
      now = i;
      ret = calc(i, 10 - i);
    }
  if (ret == 0) {
    sort(st.begin(), st.end());
    for (int i = n - 1; i >= 0; i--) cout << st[i];
    cout << endl;
    for (int i = n - 1; i >= 0; i--) cout << st[i];
    cout << endl;
  } else {
    u[now]--;
    v[10 - now]--;
    num1.push_back(now);
    num2.push_back(10 - now);
    for (int i = 0; i <= 9; i++)
      if (u[i] > 0 && v[9 - i] > 0) {
        int tmp = min(u[i], v[9 - i]);
        for (int j = 1; j <= tmp; j++) num1.push_back(i);
        for (int j = 1; j <= tmp; j++) num2.push_back(9 - i);
        u[i] -= tmp;
        v[9 - i] -= tmp;
      }
    for (int i = 1; i <= 9; i++) {
      for (int j = 1; j <= u[i]; j++) num1.push_back(i);
      for (int j = 1; j <= v[i]; j++) num2.push_back(i);
    }
    for (int i = n - 1; i >= 0; i--) cout << num1[i];
    cout << endl;
    for (int i = n - 1; i >= 0; i--) cout << num2[i];
    cout << endl;
  }
  return 0;
}
