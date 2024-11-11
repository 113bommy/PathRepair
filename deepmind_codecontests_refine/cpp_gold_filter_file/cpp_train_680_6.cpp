#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
template <class T>
inline T biton(T n, T pos) {
  return n | ((T)1 << pos);
}
template <class T>
inline T bitoff(T n, T pos) {
  return n & ~((T)1 << pos);
}
template <class T>
inline T ison(T n, T pos) {
  return (bool)(n & ((T)1 << pos));
}
template <class T>
inline T gcd(T a, T b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
template <typename T>
string NumberToString(T Number) {
  ostringstream second;
  second << Number;
  return second.str();
}
inline int nxt() {
  int aaa;
  scanf("%d", &aaa);
  return aaa;
}
inline long long int lxt() {
  long long int aaa;
  scanf("%I64d", &aaa);
  return aaa;
}
inline double dxt() {
  double aaa;
  scanf("%lf", &aaa);
  return aaa;
}
template <class T>
inline T bigmod(T p, T e, T m) {
  T ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % m;
    p = (p * p) % m;
  }
  return (T)ret;
}
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
vector<int> ar;
vector<int> br;
vector<pair<int, string> > ans;
bool go(int x, int y) {
  vector<long long int> v;
  for (int i = x; i <= y; i++) {
    v.push_back(ar[i]);
  }
  for (int i = x; i < y; i++) ar.erase(ar.begin());
  while (1) {
    if (v.size() == 1) {
      return true;
    }
    long long int mx = 0;
    for (int i = 0; i < v.size(); i++) {
      mx = max(mx, v[i]);
    }
    bool khailo = false;
    for (int i = 0; i < v.size(); i++) {
      if (v[i] == mx) {
        if (i == 0) {
          if (v[i + 1] < v[i]) {
            khailo = true;
            v[i] += v[i + 1];
            v.erase(v.begin() + i + 1);
            ans.push_back(pair<int, string>(x + i + 1, "R"));
            break;
          }
        } else if (i == v.size() - 1) {
          if (v[i - 1] < v[i]) {
            khailo = true;
            v[i] += v[i - 1];
            v.erase(v.begin() + i - 1);
            ans.push_back(pair<int, string>(x + i + 1, "L"));
            break;
          }
        } else {
          if (v[i + 1] < v[i]) {
            khailo = true;
            v[i] += v[i + 1];
            v.erase(v.begin() + i + 1);
            ans.push_back(pair<int, string>(x + i + 1, "R"));
            break;
          } else if (v[i] > v[i - 1]) {
            khailo = true;
            v[i] += v[i - 1];
            v.erase(v.begin() + i - 1);
            ans.push_back(pair<int, string>(x + i + 1, "L"));
            break;
          }
        }
      }
    }
    if (!khailo) return false;
  }
}
int main() {
  int n = nxt();
  long long int s1 = 0, s2 = 0;
  for (int i = 0; i < n; i++) {
    int a = nxt();
    ar.push_back(a);
    s1 += a;
  }
  int m = nxt();
  for (int i = 0; i < m; i++) br.push_back(nxt()), s2 += br[i];
  if (s1 != s2) {
    puts("NO");
    return 0;
  }
  for (int i = 0; i < m; i++) {
    long long int sum = 0;
    for (int j = i; j < n; j++) {
      sum += ar[j];
      if (sum == br[i]) {
        bool ans = go(i, j);
        if (ans == false) {
          puts("NO");
          return 0;
        }
        break;
      } else if (sum > br[i]) {
        puts("NO");
        return 0;
      }
    }
    if (sum < br[i]) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  for (int i = 0; i < ans.size(); i++) {
    printf("%d %s\n", ans[i].first, ans[i].second.c_str());
  }
  return 0;
}
