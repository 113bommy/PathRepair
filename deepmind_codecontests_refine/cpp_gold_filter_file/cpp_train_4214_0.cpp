#include <bits/stdc++.h>
const long long inf = 0x3f3f3f3f3f3f3f3LL;
const long long mod = (long long)1e9 + 7;
using namespace std;
template <class T, class T2>
void smin(T& a, T2 val) {
  if (a > val) a = val;
}
template <class T, class T2>
void smax(T& a, T2 val) {
  if (a < val) a = val;
}
const long long N = 5 * (long long)1e5 + 10;
long long n;
vector<long long> a;
bool check(vector<long long>& v) {
  return 5 * v[0] + v[1] + v[2] - 3 * v[3] == 0;
}
bool check2(vector<long long>& v) {
  long long x1 = v[0], x2 = v[1], x3 = v[2], x4 = v[3];
  return x1 - x2 - x3 + x4 == 0;
}
bool check3(vector<long long>& v) {
  long long x1 = v[0], x2 = v[1], x3 = v[2], x4 = v[3];
  return 2 * x1 + x2 + x3 - 2 * x4 == 0;
}
bool valid(vector<long long>& v) {
  for (auto& it : v) {
    if (!(it >= 1 and it <= 1e6)) {
      return false;
    }
  }
  return true;
}
bool good(vector<long long>& v) {
  return (long long)(v.size()) == 4 and valid(v) and check(v) and check2(v) and
         check3(v) and is_sorted(v.begin(), v.end());
}
void print(vector<long long>& v, vector<long long>& a) {
  assert((long long)(v.size()) == 4);
  multiset<long long> ms;
  for (auto it : v) ms.insert(it);
  for (auto& it : a) {
    assert(ms.find(it) != ms.end());
    ms.erase(ms.find(it));
  }
  cout << "YES" << '\n';
  for (auto& it : ms) {
    cout << it << '\n';
  }
  exit(0);
}
void make(long long x1, long long x4) {
  for (long long b = 1; b <= 1e6; ++b) {
    long long other = 4 * x1 - b;
    vector<long long> t;
    t.push_back(x1);
    t.push_back(b);
    t.push_back(other);
    t.push_back(x4);
    if (is_sorted(t.begin(), t.end()) and good(t)) {
      print(t, a);
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  if (n == 0) {
    cout << "YES" << '\n';
    cout << "1\n1\n3\n3\n";
    exit(0);
  }
  a.resize(n);
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  if (n == 1) {
    for (long long b = 1; b <= 1e6; ++b) {
      long long other = 4 * a[0] - b;
      if (other >= b and b >= a[0] and other <= 3 * a[0]) {
        vector<long long> t;
        t.push_back(a[0]);
        t.push_back(b);
        t.push_back(other);
        t.push_back(3 * a[0]);
        if (good(t)) {
          print(t, a);
        }
      }
    }
    for (long long i = a[0]; i <= 1e6; ++i) {
      long long sum = a[0] + i;
      if (sum % 4) {
        continue;
      }
      sum /= 4;
      if (sum >= 1 and sum <= a[0]) {
        vector<long long> t;
        t.push_back(sum);
        t.push_back(a[0]);
        t.push_back(i);
        t.push_back(3 * sum);
        if (good(t)) {
          print(t, a);
        }
      }
    }
    for (long long i = a[0]; i >= 1; --i) {
      long long sum = a[0] + i;
      if (sum % 4) {
        continue;
      }
      sum /= 4;
      if (sum >= 1 and sum <= a[0]) {
        vector<long long> t;
        t.push_back(sum);
        t.push_back(i);
        t.push_back(a[0]);
        t.push_back(3 * sum);
        if (good(t)) {
          print(t, a);
        }
      }
    }
    if (a[0] % 4) {
      cout << "NO";
      exit(0);
    }
    long long curr = a[0] / 4;
    if (curr >= 1 and curr <= 1e6) {
      for (long long b = 1; b <= 1e6; ++b) {
        long long other = 4 * curr - b;
        if (other >= b and b >= curr and other <= a[0]) {
          vector<long long> t;
          t.push_back(curr);
          t.push_back(b);
          t.push_back(other);
          t.push_back(a[0]);
          if (good(t)) {
            print(t, a);
          }
        }
      }
    }
  }
  if (n == 2) {
    long long x1, x2;
    long long x4 = 3 * a[0];
    long long x3 = 4 * a[0] - a[1];
    vector<long long> t = {a[0], a[1], x3, x4};
    if (good(t)) {
      print(t, a);
    }
    x1 = a[0];
    x3 = a[1];
    x2 = 4 * x1 - x3;
    x4 = 3 * x1;
    t = {x1, x2, x3, x4};
    if (good(t)) {
      print(t, a);
    }
    x1 = a[0];
    x4 = a[1];
    if (x4 == 3 * x1) {
      make(x1, x4);
    }
    x2 = a[0];
    x3 = a[1];
    if ((x2 + x3) % 4 == 0) {
      x1 = (x2 + x3) / 4;
      x4 = 3 * x1;
      t = {x1, x2, x3, x4};
      if (good(t)) {
        print(t, a);
      }
    }
    x2 = a[0];
    x4 = a[1];
    if (x4 % 3 == 0) {
      x1 = x4 / 3;
      x3 = 4 * x1 - x2;
      t = {x1, x2, x3, x4};
      if (good(t)) {
        print(t, a);
      }
    }
    x3 = a[0];
    x4 = a[1];
    if (x4 % 3 == 0) {
      x1 = x4 / 3;
      x2 = 4 * x1 - x3;
      t = {x1, x2, x3, x4};
      if (good(t)) {
        print(t, a);
      }
    }
  }
  if (n == 3) {
    long long x1, x2, x3, x4;
    x2 = a[0], x3 = a[1], x4 = a[2];
    vector<long long> t;
    if (x4 % 3 == 0) {
      x1 = x4 / 3;
      t = {x1, x2, x3, x4};
      if (good(t)) {
        print(t, a);
      }
    }
    x1 = a[0], x3 = a[1], x4 = a[2];
    x2 = 4 * x1 - x3;
    t = {x1, x2, x3, x4};
    if (good(t)) {
      print(t, a);
    }
    x1 = a[0], x2 = a[1], x4 = a[2];
    x3 = 4 * x1 - x2;
    t = {x1, x2, x3, x4};
    if (good(t)) {
      print(t, a);
    }
    x1 = a[0], x2 = a[1], x3 = a[2];
    x4 = 3 * x1;
    t = {x1, x2, x3, x4};
    if (good(t)) {
      print(t, a);
    }
  }
  if (n == 4) {
    vector<long long> v = a;
    sort(v.begin(), v.end());
    if (good(v)) {
      cout << "YES";
      exit(0);
    }
  }
  cout << "NO";
  return 0;
}
