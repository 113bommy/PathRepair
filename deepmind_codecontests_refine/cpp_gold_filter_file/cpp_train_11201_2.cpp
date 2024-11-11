#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
const int MAX = 4007;
const int MAX2 = 1000000;
const int MAXD = 20;
const int BASE = 1000000007;
const int MOD = 1000000007;
const int psz = 2000006;
int fx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int fy[] = {-1, +1, +0, +0, +1, +1, -1, -1};
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
inline int number_of_edges(int degreeofvertices) {
  int res;
  res = (degreeofvertices) / 2;
  return res;
};
inline int josephus(int n, int k) {
  if (n == 1) {
    return 1;
  } else {
    return (josephus(n - 1, k) + k - 1) % n + 1;
  }
}
inline int binary_src(int a[], int n, int k) {
  int lo = 0, hi = n - 1, mid;
  while (lo <= hi) {
    mid = (lo + hi) / 2;
    if (a[mid] == k) {
      return mid + 1;
    } else if (a[mid] > k) {
      hi = mid - 1;
    } else if (a[mid] < k) {
      lo = mid + 1;
    }
  }
  return -1;
}
inline bool isLeap(long long int y) {
  return (y % 400 == 0) || (y % 100 ? y % 4 == 0 : false);
}
inline int chToIn(char a) {
  int b;
  b = a - '0';
  return b;
}
inline char inTOch(int a) {
  char b;
  b = a + '0';
  return b;
}
inline int stToIn(string a) {
  int b;
  b = atoi(a.c_str());
  return b;
}
inline string appendChar(string s, char a) {
  s.append(1, a);
  return s;
}
inline string rev(string a) {
  int siz = (int)a.size();
  string res = "";
  for (int i = (siz)-1; i >= (0); --i) {
    res += a[i];
  }
  return res;
}
inline int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b))); }
vector<long long int> factors_n;
inline long long int factor_find_n(long long int n) {
  for (long long int i = 2; i <= n; i++)
    while (n % i == 0) {
      n /= i;
      factors_n.push_back(i);
    }
}
vector<long long int> factors_sqr;
inline long long int factor_find_sqrt(long long int n) {
  for (long long int i = 2; i * i <= n; i++)
    while (n % i == 0) {
      n /= i;
      factors_sqr.push_back(i);
    }
}
inline long long int bigmod(long long int a, long long int b, long long int m) {
  if (b == 0) return 1 % m;
  long long int x = bigmod(a, b / 2, m);
  x = (x * x) % m;
  if (b % 2 == 1) {
    x = (x * a) % m;
  }
  return x;
}
inline long long int phi(long long int n) {
  long long int ret = n;
  for (long long int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) n /= i;
    }
    ret -= ret / i;
  }
  if (n > 1) {
    ret -= ret / n;
  }
  return ret;
}
pair<int, int> my[10000];
pair<int, int> s[10000];
int main() {
  int n;
  cin >> n;
  int sum1 = 0, sum2 = 0, k = 0;
  bool ok = false;
  for (int i = (0); i < (n); i++) {
    int a, b;
    cin >> a >> b;
    sum1 += a;
    sum2 += b;
    my[i].first = a;
    my[i].second = b;
    s[i].first = a;
    s[i].second = b;
    if (a != b) {
      ok = true;
    }
  }
  if (ok) {
    cout << "rated" << endl;
    return 0;
  } else {
    int j = 0;
    int f = 0;
    sort(my, my + n);
    for (int i = (n)-1; i >= (0); --i) {
      if ((my[i].first == s[j].first) && (my[i].second == s[j].second)) {
        f = 0;
      } else {
        f = 1;
        break;
      }
      j++;
    }
    if (f == 0) {
      cout << "maybe" << endl;
    } else {
      cout << "unrated" << endl;
    }
  }
  return 0;
}
