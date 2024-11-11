#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline string tostring(T a) {
  ostringstream os("");
  os << a;
  return os.str();
}
template <typename T>
inline long long tolong(T a) {
  long long res;
  istringstream os(a);
  os >> res;
  return res;
}
template <typename T>
inline vector<int> parse(T str) {
  vector<int> res;
  int s;
  istringstream os(str);
  while (os >> s) res.push_back(s);
  return res;
}
template <class T>
inline T _sqrt(T x) {
  return (T)sqrt((double)x);
}
template <class T>
inline T _bigmod(T n, T m) {
  T ans = 1, mult = n % 1e9 + 7;
  while (m) {
    if (m & 1) ans = (ans * mult) % 1e9 + 7;
    m >>= 1;
    mult = (mult * mult) % 1e9 + 7;
  }
  ans %= 1e9 + 7;
  return ans;
}
template <class T>
inline T _modinv(T x) {
  return _bigmod(x, (T)1e9 + 7 - 2) % 1e9 + 7;
}
inline int len(string a) { return a.length(); }
inline int len(char a[]) { return strlen(a); }
template <class T>
inline T _gcd(T a, T b) {
  return (b == 0) ? a : _gcd(b, a % b);
}
template <class T>
inline T _lcm(T x, T y) {
  return x * y / _gcd(x, y);
}
vector<int> prime;
bool pr[10000009];
void seive() {
  memset(pr, true, sizeof(pr));
  pr[0] = pr[1] = false;
  for (int i = 2; i * i <= 10000000; i++) {
    if (pr[i] == true) {
      for (int j = i * 2; j <= 10000000; j += i) {
        pr[j] = false;
      }
    }
  }
  for (int i = 3; i <= 1000000; i++) {
    if (pr[i] == true) {
      prime.push_back(i);
    }
  }
}
struct edge {
  int x, y, w;
};
int main() {
  clock_t begin = clock();
  seive();
  int n, m;
  cin >> n >> m;
  int c1 = 1;
  int c2 = 2;
  int total_sum = 0;
  int min_sum = 0;
  vector<edge> v;
  for (int i = 1; i < n; i++) {
    int next_prime =
        lower_bound(prime.begin(), prime.end(), total_sum) - prime.begin();
    if (prime[next_prime] <= total_sum) next_prime++;
    int next = prime[next_prime];
    int need = next - total_sum;
    total_sum += need;
    v.push_back({c1, c2, need});
    c1 = c2;
    c2++;
  }
  cout << total_sum << " " << total_sum << endl;
  m -= n - 1;
  for (int i = 1; i < n && m; i++) {
    for (int j = i + 2; j <= n && m; j++) {
      v.push_back({i, j, 10000000});
      m--;
    }
  }
  for (int i = 0; i < v.size(); i++) {
    cout << v[i].x << " " << v[i].y << " " << v[i].w << endl;
  }
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  return 0;
}
