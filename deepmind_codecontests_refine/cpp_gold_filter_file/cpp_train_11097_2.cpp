#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
string print_iterable(T1 begin_iter, T2 end_iter, int counter) {
  bool done_something = false;
  stringstream res;
  res << "[";
  for (; begin_iter != end_iter and counter; ++begin_iter) {
    done_something = true;
    counter--;
    res << *begin_iter << ", ";
  }
  string str = res.str();
  if (done_something) {
    str.pop_back();
    str.pop_back();
  }
  str += "]";
  return str;
}
vector<int> SortIndex(int size, std::function<bool(int, int)> compare) {
  vector<int> ord(size);
  for (int i = 0; i < size; i++) ord[i] = i;
  sort(ord.begin(), ord.end(), compare);
  return ord;
}
template <typename T>
bool MinPlace(T& a, const T& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
bool MaxPlace(T& a, const T& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename S, typename T>
ostream& operator<<(ostream& out, const pair<S, T>& p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  out << "[";
  for (int i = 0; i < (int)v.size(); i++) {
    out << v[i];
    if (i != (int)v.size() - 1) out << ", ";
  }
  out << "]";
  return out;
}
const long long mod = 1e9 + 7;
long long p[100];
long long ComputeNum(long long k, int i, int j) {
  if (i < j) swap(i, j);
  if (1 << i <= k) return p[i + j];
  long long res = p[j] % mod;
  for (int s = 0; 1 << s <= k; s++) {
    if (k & 1 << s) {
      res += p[s + j];
      res %= mod;
    }
  }
  return res;
}
long long ComputeSum(long long k, int i, int j) {
  if (i < j) swap(i, j);
  if (1 << i <= k) {
    long long res1 = p[j];
    long long res2 = (p[i] * (p[i] - 1ll)) / 2ll;
    res1 %= mod;
    res2 %= mod;
    return (res1 * res2) % mod;
  }
  long long res = (p[j] * k) % mod;
  for (int s = 0; (1 << s) <= k; s++) {
    if (k & (1 << s)) {
      long long ris1 = (k - k % (1 << (s + 1))) % mod;
      long long ris2 = ((p[s] * (p[s] - 1ll)) / 2ll) % mod;
      ris1 *= p[j + s];
      ris2 *= p[j];
      res += (ris1 + ris2) % mod;
      res %= mod;
    }
  }
  return res;
}
long long SimpleSum(long long k, int x, int y) {
  long long ans = 0;
  if (x <= 0 or y <= 0) return 0;
  for (int i = 0; 1 << i <= x; i++) {
    for (int j = 0; 1 << j <= y; j++) {
      if (x & (1 << i) && y & (1 << j)) {
        int x1 = x - x % (1 << max(i + 1, j));
        int y1 = y - y % (1 << max(i, j + 1));
        int v = x1 ^ y1;
        if (k < v) continue;
        ans += (long long)(1 + v) * ComputeNum(k - v, i, j) +
               ComputeSum(k - v, i, j);
        ans %= mod;
      }
    }
  }
  return ans;
}
long long GetSum(int x1, int y1, int x2, int y2, long long k) {
  long long res = SimpleSum(k - 1, x2, y2) - SimpleSum(k - 1, x2, y1) -
                  SimpleSum(k - 1, x1, y2) + SimpleSum(k - 1, x1, y1);
  res %= mod;
  res += mod;
  return res % mod;
}
int main() {
  p[0] = 1;
  for (int i = 1; i < 100; i++) p[i] = (p[i - 1] * 2ll) % mod;
  ios::sync_with_stdio(false);
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int x1, y1, x2, y2;
    long long k;
    cin >> x1 >> y1 >> x2 >> y2 >> k;
    cout << GetSum(x1 - 1, y1 - 1, x2, y2, k) << "\n";
  }
}
