#include <bits/stdc++.h>
const double PI =
    3.14159265358979323846264338327950288419716939937510582097494459230;
const long long int MOD = 1e9 + 7;
using namespace std;
long long int prime(long long int n) {
  if (n % 2 == 0 && n != 2 || n < 2)
    return false;
  else {
    for (long long int i = 3; i * i <= n; i += 2) {
      if (n % i == 0) {
        return false;
      }
    }
  }
  return true;
}
long long int gcd(long long int n, long long int m) {
  if (n % m == 0)
    return m;
  else
    return gcd(m, n % m);
}
long long int lcm(long long int n, long long int m) {
  return n * m / gcd(n, m);
}
long long int fact(long long int n) {
  if (n == 1)
    return 1;
  else
    return n * fact(n - 1);
}
int sumdigit(int n) {
  int sum = 0;
  while (n) {
    sum += (n % 10);
    n /= 10;
  }
  return sum;
}
string tobinary(long long int n) {
  string s;
  while (n) {
    s += (n % 2) + '0';
    n /= 2;
  }
  reverse((s).begin(), (s).end());
  return s;
}
string tostring(double n) {
  double m = n;
  string x;
  stringstream ss;
  ss << m;
  ss >> x;
  return x;
}
char tochar(int n) {
  int m = n;
  char x;
  stringstream ss;
  ss << m;
  ss >> x;
  return x;
}
void div(long long int l, long long int r, long long int n) {
  long long int x = 0;
  for (long long int i = 1; i <= l; i++) {
    if (i % n == 0) {
      x = i;
    }
  }
  if (!x) {
    for (long long int i = r;; i++) {
      if (i % n == 0) {
        x = i;
      }
    }
  }
}
float log2(int n) { return log10(n) / log10(2); }
string reverse_(string s) {
  string x;
  for (int i = s.size() - 1; i >= 0; i--) x += s[i];
  return x;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<char> v;
  vector<int> vint;
  int c = 0, mx = 0, n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  v.push_back(s[0]);
  if (n > 1) {
    for (int i = 0; i < s.size() - 1; i++) {
      if (s[i] == s[i + 1])
        c++;
      else {
        c++;
        if (vint.size() < 1) {
          vint.push_back(c / k);
          c = 0;
        }
        for (int j = 0; j < v.size(); j++) {
          if (s[i] == v[j]) {
            vint[j] += (c / k);
            break;
          } else if (j == v.size() - 1) {
            v.push_back(s[i]);
            vint.push_back(c / k);
            break;
          }
        }
        c = 0;
      }
    }
    if (vint.size() < 1) {
      vint.push_back(c + 1 / k);
      c = 0;
    }
    if (c) {
      c++;
      for (int j = 0; j < v.size(); j++) {
        if (s[n - 1] == v[j]) {
          vint[j] += (c / k);
          break;
        } else if (j == v.size() - 1) {
          v.push_back(s[n - 1]);
          vint.push_back(c / k);
          break;
        }
      }
    }
    for (int i = 0; i < vint.size(); i++) {
      mx = max(vint[i], mx);
    }
  } else
    mx = 1 / k;
  cout << mx;
  return 0;
}
