#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int inf = 2000000000;
const long long infLL = 9000000000000000000;
template <typename first, typename second>
ostream& operator<<(ostream& os, const pair<first, second>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "{";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "}";
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ",";
    os << *it;
  }
  return os << "]";
}
template <typename T>
ostream& operator<<(ostream& os, const multiset<T>& v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}
template <typename first, typename second>
ostream& operator<<(ostream& os, const map<first, second>& v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << it->first << " = " << it->second;
  }
  return os << "]";
}
void faltu() { cerr << '\n'; }
template <typename T>
void faltu(T a[], int n) {
  for (int i = 0; i < n; ++i) cerr << a[i] << ' ';
  cerr << '\n';
}
template <typename T, typename... hello>
void faltu(T arg, const hello&... rest) {
  cerr << arg << ' ';
  faltu(rest...);
}
const int mx = 2e5 + 5;
int n, m, k, q;
int r[mx], c[mx];
int b[mx];
vector<int> vec[mx];
map<int, long long> dp[mx];
int lim;
int jump[mx];
long long recur(int posR, int posC) {
  if (posR == lim) {
    if (posC < vec[posR][0]) return vec[posR].back() - posC;
    if (posC > vec[posR].back()) return posC - vec[posR][0];
    if (posC >= vec[posR][0] && posC <= vec[posR].back()) {
      return min(posC - vec[posR][0] + vec[posR].back() - vec[posR][0],
                 vec[posR].back() - posC + vec[posR].back() - vec[posR][0]);
    }
  }
  if (dp[posR].lower_bound(posC) != dp[posR].upper_bound(posC))
    return dp[posR][posC];
  int c = jump[posR] - posR;
  if (vec[posR].empty()) {
    int idx = posC;
    long long sum = 0;
    int ul = lower_bound(b, b + q, idx) - b;
    if (posC != b[ul]) {
      if (ul == q) {
        --ul;
        long long temp = sum + idx - b[ul] + c + recur(jump[posR], b[ul]);
        dp[posR][posC] = temp;
        return temp;
      } else if (ul == 0) {
        long long temp = sum + b[ul] - idx + c + recur(jump[posR], b[ul]);
        dp[posR][posC] = temp;
        return temp;
      } else {
        long long temp1 = sum + b[ul] - idx + c + recur(jump[posR], b[ul]);
        --ul;
        long long temp2 = sum + idx - b[ul] + c + recur(jump[posR], b[ul]);
        dp[posR][posC] = min(temp1, temp2);
        return min(temp1, temp2);
      }
    } else {
      dp[posR][posC] = c + recur(jump[posR], posC);
      return dp[posR][posC];
    }
  }
  if (posC < vec[posR][0]) {
    long long sum = 0;
    sum += vec[posR].back() - posC;
    int idx = vec[posR].back();
    int ul = lower_bound(b, b + q, idx) - b;
    if (ul == q) {
      --ul;
      long long temp = sum + idx - b[ul] + c + recur(jump[posR], b[ul]);
      dp[posR][posC] = temp;
      return temp;
    } else if (ul == 0) {
      long long temp = sum + b[ul] - idx + c + recur(jump[posR], b[ul]);
      dp[posR][posC] = temp;
      return temp;
    } else {
      long long temp1 = sum + b[ul] - idx + c + recur(jump[posR], b[ul]);
      --ul;
      long long temp2 = sum + idx - b[ul] + c + recur(jump[posR], b[ul]);
      dp[posR][posC] = min(temp1, temp2);
      return min(temp1, temp2);
    }
  }
  if (posC > vec[posR].back()) {
    long long sum = 0;
    sum += posC - vec[posR][0];
    int idx = vec[posR][0];
    int ul = lower_bound(b, b + q, idx) - b;
    if (ul == q) {
      --ul;
      long long temp = sum + idx - b[ul] + c + recur(jump[posR], b[ul]);
      dp[posR][posC] = temp;
      return temp;
    } else if (ul == 0) {
      long long temp = sum + b[ul] - idx + c + recur(jump[posR], b[ul]);
      dp[posR][posC] = temp;
      return temp;
    } else {
      long long temp1 = sum + b[ul] - idx + c + recur(jump[posR], b[ul]);
      --ul;
      long long temp2 = sum + idx - b[ul] + c + recur(jump[posR], b[ul]);
      dp[posR][posC] = min(temp1, temp2);
      return min(temp1, temp2);
    }
  }
  if (posC >= vec[posR][0] && posC <= vec[posR].back()) {
    long long ret = infLL;
    long long sum1 = 0;
    sum1 += posC - vec[posR][0] + vec[posR].back() - vec[posR][0];
    int idx = vec[posR].back();
    int ul = lower_bound(b, b + q, idx) - b;
    if (ul == q) {
      --ul;
      long long temp = sum1 + idx - b[ul] + c + recur(jump[posR], b[ul]);
      ret = min(ret, temp);
    } else if (ul == 0) {
      long long temp = sum1 + b[ul] - idx + c + recur(jump[posR], b[ul]);
      ret = min(ret, temp);
    } else {
      long long temp1 = sum1 + b[ul] - idx + c + recur(jump[posR], b[ul]);
      --ul;
      long long temp2 = sum1 + idx - b[ul] + c + recur(jump[posR], b[ul]);
      ret = min({ret, temp1, temp2});
    }
    long long sum2 = 0;
    sum2 += vec[posR].back() - posC + vec[posR].back() - vec[posR][0];
    idx = vec[posR][0];
    ul = lower_bound(b, b + q, idx) - b;
    if (ul == q) {
      --ul;
      long long temp = sum2 + idx - b[ul] + c + recur(jump[posR], b[ul]);
      ret = min(ret, temp);
    } else if (ul == 0) {
      long long temp = sum2 + b[ul] - idx + c + recur(jump[posR], b[ul]);
      ret = min(ret, temp);
    } else {
      long long temp1 = sum2 + b[ul] - idx + c + recur(jump[posR], b[ul]);
      --ul;
      long long temp2 = sum2 + idx - b[ul] + c + recur(jump[posR], b[ul]);
      ret = min({ret, temp1, temp2});
    }
    dp[posR][posC] = ret;
    return ret;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> m >> k >> q;
  for (int i = 0; i < k; ++i) {
    cin >> r[i] >> c[i];
    vec[r[i]].push_back(c[i]);
  }
  for (int i = 1; i <= n; ++i) sort(vec[i].begin(), vec[i].end());
  for (int i = 1; i <= n; ++i)
    if (!vec[i].empty()) lim = i;
  for (int i = lim - 1; i >= 1; --i) {
    if (!vec[i + 1].empty())
      jump[i] = i + 1;
    else
      jump[i] = jump[i + 1];
  }
  for (int i = 0; i < q; ++i) {
    cin >> b[i];
  }
  sort(b, b + q);
  long long ans = recur(1, 1);
  cout << ans << '\n';
}
