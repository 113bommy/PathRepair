#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T maxi(T a, T b) {
  return a > b ? a : b;
}
template <typename T>
inline T mini(T a, T b) {
  return a < b ? a : b;
}
template <typename T>
inline T absl(T a) {
  return a > 0 ? a : -a;
}
template <typename T>
inline T gcd(T a, T b) {
  T t;
  if (a < b) {
    while (a) {
      t = a;
      a = b % a;
      b = t;
    }
    return b;
  } else {
    while (b) {
      t = b;
      b = a % b;
      a = t;
    }
    return a;
  }
}
template <typename T>
inline T ceiling(T a, T b) {
  if (a % b == 0) return (a / b);
  return ((a / b) + 1);
}
void input() {
  long long int n, m;
  cin >> n >> m;
  vector<long long int> a(n);
  for (long long int i = 0; i < n; ++i) cin >> a[i];
  int l[m], r[m];
  for (int i = 0; i < m; ++i) {
    cin >> l[i] >> r[i];
    --l[i];
    --r[i];
  }
  int ans = INT_MIN;
  vector<int> finala;
  for (int i = 0; i < n; ++i) {
    vector<int> c;
    vector<int> s(n + 1, 0);
    int len = 0;
    for (int j = 0; j < m; ++j) {
      if (l[j] <= i && r[j] >= i) {
        c.push_back(j + 1);
        s[l[j]] += -1;
        s[r[j] + 1] -= -1;
        ++len;
      }
    }
    for (int i = 1; i < n; ++i) {
      s[i] += s[i - 1];
    }
    for (int i = 0; i < n; ++i) s[i] += a[i];
    int max = *(max_element(s.begin(), s.end() - 1));
    int min = a[i] - len;
    if ((max - min) > ans) {
      ans = max - min;
      finala = c;
    }
  }
  cout << ans << endl << finala.size() << endl;
  for (auto it : finala) {
    cout << it << " ";
  }
  cout << endl;
}
int main() {
  input();
  return 0;
}
