#include <bits/stdc++.h>
using namespace std;
template <class T>
T Bitcnt(T a) {
  int sum = 0;
  while (a) {
    if (a & 1) sum++;
    a /= 2;
  }
  return sum;
}
template <class T>
T Max3(T a, T b, T c) {
  return max(a, max(b, c));
}
template <class T>
T Lcm(T a, T b) {
  T tmp = __gcd(a, b);
  return (a / tmp) * b;
}
template <class T>
T Pow(T a, T b) {
  T ans = 1;
  T base = a;
  while (b) {
    if (b & 1) ans = (ans * base);
    base = (base * base);
    b /= 2;
  }
  return ans;
}
long long Bigmod(long long a, long long b) {
  long long res = 1;
  long long pw = a % 1000000007LL;
  while (b > 0) {
    if (b & 1) res = (res * pw) % 1000000007LL;
    pw = (pw * pw) % 1000000007LL;
    b /= 2;
  }
  return res;
}
int a_x[] = {1, -1, 0, 0};
int a_y[] = {0, 0, 1, -1};
long long X, Y;
void extend_euclid(long long a, long long b) {
  if (b == 0) {
    X = a;
    Y = 0;
    return;
  }
  extend_euclid(b, a % b);
  long long x, y;
  x = Y;
  y = X - (a / b) * Y;
  X = x;
  Y = y;
}
long long inverse_modulo(long long a, long long b) {
  extend_euclid(a, b);
  return (X + 1000000007LL) % 1000000007LL;
}
int b[4000000];
map<int, int> cnt;
set<int> st;
int tot[4000000];
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i <= n - 1; i++) {
    scanf("%d", &b[i]);
    cnt[b[i]]++;
    st.insert(b[i]);
  }
  int len = 0;
  int lcm = 1;
  for (set<int>::iterator it = st.begin(); it != st.end(); it++) {
    int val = *it;
    for (int j = val; j <= k; j += val) {
      tot[j] = cnt[val] + tot[j];
      if (tot[j] > len) {
        len = tot[j];
        lcm = j;
      }
    }
  }
  cout << lcm << " " << len << endl;
  for (int i = 0; i <= n - 1; i++) {
    if (lcm % b[i] == 0) printf("%d ", i + 1);
  }
  return 0;
}
