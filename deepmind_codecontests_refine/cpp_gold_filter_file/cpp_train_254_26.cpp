#include <bits/stdc++.h>
using namespace std;
template <typename S, typename T>
ostream& operator<<(ostream& out, pair<S, T> const& p) {
  out << '(' << p.first << ", " << p.second << ')';
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T> const& v) {
  long long l = v.size();
  for (long long i = 0; i < l - 1; i++) out << v[i] << ' ';
  if (l > 0) out << v[l - 1];
  return out;
}
template <typename T>
void trace(const char* name, T&& arg1) {
  cout << name << " : " << arg1 << "\n";
}
template <typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  trace(comma + 1, args...);
}
long long n, k;
vector<long long> v;
vector<bool> check;
void solve(long long beg, long long end, long long i) {
  if (beg == i or end + k > n) {
    long long left = INT_MIN, right = INT_MAX;
    long long cnt = (end - beg) / k + 1;
    if (beg != i) left = v[beg - k];
    if (end + k <= n) right = v[end + k];
    if (left >= 0) {
      long long val = left + 1;
      for (long long p = beg; p <= end; p += k) v[p] = val++;
      return;
    } else if (right <= 0) {
      long long val = right - 1;
      for (long long p = end; p >= beg; p -= k) v[p] = val--;
      return;
    }
    set<long long> val;
    val.insert(0);
    long long x = 1, done = 1;
    while (done < cnt) {
      if (-1 * x > left) {
        val.insert(-1 * x);
        done++;
      }
      if (done == cnt) break;
      if (x < right) {
        val.insert(x);
        done++;
      }
      x++;
    }
    for (long long p = beg; p <= end; p += k) {
      v[p] = (*val.begin());
      val.erase(*val.begin());
    }
  } else {
    long long cnt = (end - beg) / k + 1;
    if (v[end + k] - v[beg - k] - 1 < cnt) {
      cout << "Incorrect sequence\n";
      exit(0);
    }
    if (v[beg - k] >= 0) {
      long long val = v[beg - k] + 1;
      for (long long p = beg; p <= end; p += k) v[p] = val++;
    } else if (v[beg - k] <= 0 and v[end + k] <= 0) {
      long long val = v[end + k] - 1;
      for (long long p = end; p >= beg; p -= k) v[p] = val--;
    } else {
      long long left = v[beg - k], right = v[end + k];
      set<long long> val;
      val.insert(0);
      long long x = 1, done = 1;
      while (done < cnt) {
        if (-1 * x > left) {
          val.insert(-1 * x);
          done++;
        }
        if (done == cnt) break;
        if (x < right) {
          val.insert(x);
          done++;
        }
        x++;
      }
      for (long long p = beg; p <= end; p += k) {
        v[p] = (*val.begin());
        val.erase(*val.begin());
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;
  v.resize(n + 1, 0);
  check.resize(n + 1, false);
  for (long long i = 1; i <= n; i++) {
    string x;
    cin >> x;
    if (x == "?")
      check[i] = true;
    else {
      long long num = 0;
      for (long long j = 0; x[j] != '\0'; j++) {
        if (x[j] == '-') continue;
        num = num * 10 + (x[j] - '0');
      }
      if (x[0] == '-') num = -num;
      v[i] = num;
    }
  }
  for (long long i = 1; i <= k; i++) {
    long long f = -1, l = -1;
    long long mn = INT_MIN;
    long long j;
    for (j = i; j <= n; j += k) {
      if (check[j] == true and f == -1)
        f = j;
      else if (check[j] != true and f != -1) {
        l = j - k;
        solve(f, l, i);
        f = -1;
        l = -1;
      } else if (check[j] != true and v[j] <= mn) {
        cout << "Incorrect sequence\n";
        return 0;
      }
      if (check[j] == false) mn = v[j];
    }
    if (f != -1) solve(f, j - k, i);
  }
  for (long long i = 1; i <= n; i++) cout << v[i] << " ";
  cout << "\n";
  return 0;
}
