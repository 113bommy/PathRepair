#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
long long isPrime(long long n) {
  long long p = (long long)sqrt(n);
  for (long long i = (2); i <= (p); i += (1))
    if (n % i == 0) return 0;
  return 1;
}
long long pows(long long b, long long e) {
  if (e == 0)
    return 1;
  else if (e % 2 == 0) {
    long long a = pow(b, e / 2);
    return a * a;
  } else {
    long long a = pow(b, e / 2);
    return b * a * a;
  }
}
long long powm(long long a, long long b, long long m = 1000000007) {
  long long x = 1;
  a %= 1000000007;
  while (b) {
    if (b & 1) x = x * a % 1000000007;
    a = a * a % 1000000007;
    b >>= 1;
  }
  return x;
}
long long modInverse(long long a, long long m = 1000000007) {
  return powm(a, m - 2, m);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    long long n, m, i, j, k, x, t, y, z, f, p, q, g, l, r, w, h,
        count1 = 0, count = 0, prod = 1, a, b, c, d, index, x1, x2, ans = 0,
        diff, sum = 0, sum1 = 0, sum2 = 0, flag = 0, flag1 = 0, flag2 = 0;
    string s1, s2;
    cin >> n;
    string s[n];
    unordered_map<string, long long> m2;
    pair<long long, long long> p1;
    set<long long> one_one, zero_one, one_zero, zero_zero;
    for (i = 0; i < n; i++) {
      cin >> s[i];
      if ((s[i][0] == '0' && s[i][s[i].size() - 1] == '0') ||
          (s[i].size() == 1 && s[i][0] == '1')) {
        zero_zero.insert(i);
      } else if ((s[i][0] == '1' && s[i][s[i].size() - 1] == '1') ||
                 (s[i].size() == 1 && s[i][0] == '1')) {
        one_one.insert(i);
      } else if (s[i][0] == '1' && s[i][s[i].size() - 1] == '0') {
        one_zero.insert(i);
        m2[s[i]] = 1;
        count++;
      } else if (s[i][0] == '0' && s[i][s[i].size() - 1] == '1') {
        zero_one.insert(i);
        m2[s[i]] = 1;
        count1++;
      }
    }
    if (zero_zero.size() > 0 && one_one.size() > 0 && count == 0 &&
        count1 == 0) {
      cout << "-1\n";
      continue;
    }
    if (abs(count - count1) <= 1) {
      cout << "0\n\n";
      continue;
    } else if (count > count1 + 1) {
      p = (count + count1);
      q = p / 2;
      if (p % 2 != 0) {
        q++;
      }
      diff = count - q;
      vector<long long> v;
      for (auto i : one_zero) {
        reverse(s[i].begin(), s[i].end());
        s1 = s[i];
        if (m2[s1] == 0) {
          m2[s1] = 1;
          v.push_back(i + 1);
        }
      }
      if (v.size() < diff) {
        cout << "-1\n";
        continue;
      } else {
        cout << diff << "\n";
        for (i = 0; i < diff; i++) {
          cout << v[i] << " ";
        }
        cout << "\n";
      }
      cout << "\n";
    } else if (count1 > count + 1) {
      p = (count + count1);
      q = p / 2;
      if (p % 2 != 0) {
        q++;
      }
      diff = count1 - q;
      vector<long long> v;
      for (auto i : zero_one) {
        reverse(s[i].begin(), s[i].end());
        s1 = s[i];
        if (m2[s1] == 0) {
          m2[s1] = 1;
          v.push_back(i + 1);
        }
      }
      if (v.size() < diff) {
        cout << "-1\n";
        continue;
      } else {
        cout << diff << "\n";
        for (i = 0; i < diff; i++) {
          cout << v[i] << " ";
        }
        cout << "\n";
      }
    }
  }
}
