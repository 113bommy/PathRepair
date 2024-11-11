#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 10, MX = 1e10;
map<long long, int> sp;
map<long long, string> rep;
inline int get_cost(long long x);
inline string get_rep(long long x);
int digits(long long x);
int main() {
  long long n;
  cin >> n;
  for (long long i = 2; i < N; ++i) {
    long long num = i * i, p = 2;
    while (num <= n) {
      int temp = digits(i) + digits(p) + 1;
      if (temp < digits(num)) {
        if (sp.find(num) == sp.end() or temp < sp[num]) {
          sp[num] = temp;
          rep[num] = to_string(i) + "^" + to_string(p);
        }
      }
      num *= i;
      ++p;
    }
  }
  int best = digits(n);
  string ans = to_string(n);
  for (auto &p : sp) {
    long long s1 = p.first;
    int cost = p.second;
    if (s1 == n) {
      if (cost < best) {
        cost = best;
        ans = rep[s1];
      }
    } else if (1 + cost + get_cost(n - s1) < best) {
      best = 1 + cost + get_cost(n - s1);
      ans = rep[s1] + "+" + get_rep(n - s1);
    }
    long long m = n / s1;
    int temp = cost + 1 + get_cost(m) +
               ((n - m * s1) ? (1 + digits((n - m * s1))) : 0);
    if (temp < best) {
      best = temp;
      ans = get_rep(s1) + "*" + get_rep(m);
      if (n - m * s1) {
        ans += "+" + to_string(n - m * s1);
      }
    }
    for (m = 1; m < 10; ++m) {
      if (s1 * m < n) {
        temp = cost + 3 + get_cost(n - s1 * m);
        if (temp < best) {
          best = temp;
          ans = to_string(m) + "*" + rep[s1] + "+" + get_rep(n - s1 * m);
        }
      }
    }
  }
  for (int add = 0; add < 10; ++add) {
    int cost = (add ? (1 + digits(add)) : 0);
    long long m = n - add, sq = sqrt(m);
    for (int i = 2; i <= sq; ++i) {
      if (m % i == 0) {
        int temp = 1 + get_cost(i) + get_cost(m / i) + cost;
        if (temp < best) {
          best = temp;
          ans = get_rep(i) + "*" + get_rep(m / i);
          if (add) {
            ans += "+" + to_string(add);
          }
        }
      }
    }
  }
  cout << ans;
}
inline int get_cost(long long x) {
  if (sp.find(x) != sp.end()) {
    return sp[x];
  } else {
    return digits(x);
  }
}
inline string get_rep(long long x) {
  if (rep.find(x) != rep.end()) {
    return rep[x];
  } else {
    return to_string(x);
  }
}
int digits(long long x) {
  int ans = 0;
  while (x) {
    ++ans;
    x /= 10;
  }
  return max(1, ans);
}
