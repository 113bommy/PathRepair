#include <bits/stdc++.h>
using namespace std;
template <class T>
T gcd(T a, T b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
template <class T>
T power(T a, T b) {
  T result = 1;
  while (b > 0) {
    if (b & 1) result = result * a;
    a = a * a;
    b >>= 1;
  }
  return result;
}
template <class T>
T powerMod(T a, T b, T c) {
  T result = 1 % c;
  while (b > 0) {
    if (b & 1) result = (result * a) % c;
    a = (a * a) % c;
    b >>= 1;
  }
  return result;
}
vector<long long> vec, vec2;
vector<long long> Res[10010], Res2[10010];
void eval() {
  long long N, i, j, a;
  cin >> N;
  for (j = 0; j < 3; j++) {
    vec.clear();
    vec2.clear();
    for (i = 0; i < N; i++) {
      if (i & (1 << j)) {
        vec.push_back(i);
      } else {
        vec2.push_back(i);
      }
    }
    if (vec.size()) {
      cout << vec.size() << "\n";
      for (i = 0; i < vec.size(); i++) {
        cout << vec[i] + 1 << " ";
      }
      cout << "\n";
      fflush(stdout);
      for (i = 0; i < N; i++) {
        cin >> a;
        Res[j].push_back(a);
      }
    }
    if (vec2.size() != N) {
      cout << vec2.size() << "\n";
      for (i = 0; i < vec2.size(); i++) {
        cout << vec2[i] + 1 << " ";
      }
      cout << "\n";
      fflush(stdout);
      for (i = 0; i < N; i++) {
        cin >> a;
        Res2[j].push_back(a);
      }
    }
  }
  cout << "-1\n";
  for (i = 0; i < N; i++) {
    long long res = LLONG_MAX;
    for (j = 0; j < 10; j++) {
      if (i & (1 << j) && Res2[j].size()) {
        res = min(res, Res2[j][i]);
      } else {
        if (Res[j].size()) {
          res = min(res, Res[j][i]);
        }
      }
    }
    cout << res << " ";
  }
}
int main() {
  cin.sync_with_stdio(0);
  cout.sync_with_stdio(0);
  eval();
  return 0;
}
