#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wwrite-strings"
using namespace std;
template <class T, class U>
ostream &operator<<(ostream &out, const pair<T, U> &A) {
  out << A.first << "_" << A.second;
  return out;
}
template <template <typename, typename> class ContainerT, typename ValueT>
ostream &operator<<(ostream &out,
                    const ContainerT<ValueT, std::allocator<ValueT> > &A) {
  for (__typeof((A).begin()) i = (A).begin(); i != (A).end(); ++i)
    out << *i << " ";
  return out;
}
template <template <typename, typename> class ContainerT, typename ValueT,
          typename ValueU>
ostream &operator<<(
    ostream &out, const ContainerT<pair<ValueT, ValueU>,
                                   std::allocator<pair<ValueT, ValueU> > > &A) {
  for (__typeof((A).begin()) i = (A).begin(); i != (A).end(); ++i)
    out << *i << " ";
  return out;
}
template <class T>
void mini(T &a, const T &b) {
  if (b < a) a = b;
}
template <class T>
void maxi(T &a, const T &b) {
  if (b > a) a = b;
}
int N, M, K, ans;
vector<vector<int> > A;
int dist(const vector<int> &standard, const vector<int> &target) {
  assert(standard.size() == target.size() and standard.size() == M);
  int ret = 0;
  for (int i = 0; i < (M); ++i) ret += standard[i] != target[i];
  return min(ret, M - ret);
}
bool noHope(const vector<int> &standard) {
  int curAns = 0;
  for (int i = 0; i < (N); ++i) {
    int diff = 0;
    for (int j = 0; j < (standard.size()); ++j) diff += A[i][j] != standard[j];
    curAns += min(diff, (int)standard.size() - diff);
    if (curAns > K or curAns >= ans) return true;
  }
  return false;
}
void dfs(vector<int> &standard) {
  if (standard.size() == M) {
    int curAns = 0;
    for (int j = 0; j < (N); ++j) curAns += dist(standard, A[j]);
    mini(ans, curAns);
  } else {
    standard.push_back(0);
    dfs(standard);
    standard.pop_back();
    standard.push_back(1);
    dfs(standard);
    standard.pop_back();
  }
}
long long solve() {
  cin >> N >> M >> K;
  A = vector<vector<int> >(N, vector<int>(M));
  ans = INT_MAX;
  for (int i = 0; i < (N); ++i)
    for (int j = 0; j < (M); ++j) cin >> A[i][j];
  if (N < M) {
    vector<vector<int> > A_(M, vector<int>(N));
    for (int i = 0; i < (N); ++i)
      for (int j = 0; j < (M); ++j) A_[j][i] = A[i][j];
    A = A_;
    int tmp = N;
    N = M;
    M = tmp;
  }
  if (M < 10) {
    vector<int> start;
    dfs(start);
  } else {
    for (int i = 0; i < (N); ++i) {
      vector<int> standard = A[i];
      int curAns = 0;
      for (int j = 0; j < (N); ++j) curAns += dist(standard, A[j]);
      mini(ans, curAns);
    }
  }
  if (ans == INT_MAX or ans > K) return -1;
  return ans;
}
int main() {
  cout << solve() << endl;
  return 0;
}
