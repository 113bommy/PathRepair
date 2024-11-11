#include <bits/stdc++.h>
using namespace std;
string str;
const long long MOD = 1e9 + 7;
template <class T>
inline void amin(T &x, const T &y) {
  if (y < x) x = y;
}
template <class T>
inline void amax(T &x, const T &y) {
  if (x < y) x = y;
}
int read() {
  long long s = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    s = s * 10 + c - '0';
    c = getchar();
  }
  return s * f;
}
long long Pow(long long a, long long b) {
  if (a == 1 || b == 1) return a;
  if (b % 2 == 1) return (a * Pow(a, b - 1)) % MOD;
  return (Pow(a, b / 2) * Pow(a, b / 2)) % MOD;
}
long long factorial(long long n) {
  long long ans = 1;
  while (--n) ans = (ans * (n + 1)) % MOD;
  return ans;
}
vector<bool> b(12, 0);
bool binod(int k) {
  bool arr[13][13];
  memset(arr, 0, sizeof(arr));
  int a = 0;
  for (int i = 0; i < k; i++)
    for (int j = 0; j < 12 / k; j++) {
      arr[i][j] = b[a];
      a++;
    }
  a = 0;
  bool d;
  for (int j = 0; j < 12 / k; j++) {
    d = 1;
    for (int i = 0; i < k; i++) {
      if (!arr[i][j]) d = 0;
    }
    if (d) return 1;
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = read();
  while (t--) {
    for (int i = 0; i < 12; i++) {
      char sign;
      cin >> sign;
      if (sign == 'X')
        b[i] = 1;
      else
        b[i] = 0;
    }
    vector<int> v;
    if (binod(1)) v.push_back(1);
    if (binod(2)) v.push_back(2);
    if (binod(3)) v.push_back(3);
    if (binod(4)) v.push_back(4);
    if (binod(6)) v.push_back(6);
    if (binod(12)) v.push_back(12);
    cout << v.size() << " ";
    for (int i = 0; i < v.size(); i++) {
      cout << v[i] << "x" << 12 / v[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
