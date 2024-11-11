#include <bits/stdc++.h>
using namespace std;
template <class T>
bool div2(T a) {
  return !(a & 1);
}
template <class T>
T mod(T a) {
  if (a < 0) {
    a += 1000000007;
  }
  return a % 1000000007;
}
template <class T>
T addmod(T a, T b) {
  return (mod(a) + mod(b)) % 1000000007;
}
template <class T>
T prodmod(T a, T b) {
  return (mod(a) * mod(b)) % 1000000007;
}
template <class T>
T e(T a, T b) {
  T res = 1;
  T temp = 1;
  if (b <= 1) return a;
  if (b % 2 == 0)
    res = e(a * a, b / 2);
  else {
    res *= a;
    temp = e(a, --b);
  }
  return res * temp;
}
template <class T>
T emod(T a, T b) {
  T res = 1;
  T temp = 1;
  if (b <= 1) return a;
  if (b % 2 == 0)
    res = emod(prodmod(a, a), b / 2);
  else {
    res = prodmod(a, res);
    temp = e(a, --b);
  }
  return prodmod(res, temp);
}
template <class T>
int digits(T a) {
  vector<long long> dig = {0,
                           9,
                           99,
                           999,
                           9999,
                           99999,
                           999999,
                           9999999,
                           99999999,
                           999999999,
                           9999999999,
                           99999999999,
                           999999999999,
                           9999999999999,
                           99999999999999,
                           999999999999999,
                           9999999999999999,
                           99999999999999999,
                           999999999999999999,
                           INT64_MAX};
  auto it = lower_bound(dig.begin(), dig.end(), a);
  int idx = (it - dig.begin());
  return idx;
}
template <class T>
int sumAllInts(T n) {
  int a = 1;
  int su = 0;
  while (n) {
    su += n % 10;
    n /= 10;
  }
  return su;
}
template <class T>
void split(char c, T s) {
  int n = s.size();
  int i = 0;
  while ((cout << s[i], i += 1) && (i < n) && (cout << c << ' '))
    ;
}
template <class T>
long long int fib(T a) {
  return ((a * (a + 1)) / 2);
}
template <class T>
long long int nC2(T a) {
  return ((a * (a - 1)) / 2);
}
template <class T>
vector<T> &divisors(T n) {
  vector<T> *res = new vector<T>;
  vector<T> &ret = *res;
  int R = sqrt(n);
  ret.resize(R);
  int start = 0;
  int end = R - 1;
  for (int i = 2; i <= R; i++) {
    if (n % i == 0) {
      ret[start] = i;
      start++;
      T etc = n / i;
      if (etc != i) {
        ret[end] = etc;
        end--;
      }
    }
  }
  int s = INT_MAX;
  int e = -1;
  for (int i = 0; i < R; i++) {
    if (!ret[i]) {
      s = min(s, i);
      e = i;
    }
  }
  if (e - s >= 0) ret.erase(ret.begin() + s, ret.begin() + e + 1);
  return ret;
}
template <class T>
void pvec(vector<T> &vec) {
  for (auto c : vec) cout << c << " ";
}
bool isPalindrome(string s) {
  int n = s.size();
  int sum = n - 1;
  int mid = n / 2 - 1;
  for (int i = 0; i < (int)mid + 1; i++) {
    if (s[i] != s[sum - i]) {
      return 0;
    }
  }
  return 1;
}
void solve(int &test) {
  int k;
  string s;
  cin >> s;
  cin >> k;
  int n = (int)s.size();
  int f = n / k;
  if (n % k != 0) {
    cout << "No";
    return;
  }
  for (int i = 0; i < n; i += f) {
    for (int j = i; j < f / 2; j++)
      if (s[j] != s[i + f - j - 1]) {
        cout << "NO";
        return;
      }
  }
  cout << "Yes";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int test;
  test = 0;
  if (test)
    cin >> test;
  else
    test = 1;
  while (test--) {
    solve(test);
    cout << "\n";
  }
  return 0;
}
