#include <bits/stdc++.h>
using namespace std;
template <class T>
using vec = vector<T>;
template <typename Iter>
ostream& _IterOutput_(ostream& o, Iter b, Iter e, const string ss = "",
                      const string se = "") {
  o << ss;
  for (auto it = b; it != e; it++) o << (it == b ? "" : ", ") << *it;
  return o << se;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& o, pair<T1, T2>& pair) {
  return o << "(" << pair.first << ", " << pair.second << ")";
}
template <typename T>
ostream& operator<<(ostream& o, const vector<T>& vec) {
  return _IterOutput_(o, begin(vec), end(vec), "[", "]");
}
template <typename T>
ostream& operator<<(ostream& o, const set<T>& st) {
  return _IterOutput_(o, begin(st), end(st), "{", "}");
}
template <typename T, size_t N>
ostream& operator<<(ostream& o, const array<T, N>& arr) {
  return _IterOutput_(o, begin(arr), end(arr), "|", "|");
}
using vint = vec<int>;
const int MX = 202020;
int o1[MX], o2[MX];
int fv[MX];
bool kmp(int N, int M) {
  int t = -1;
  fv[0] = -1;
  for (int(i) = (1); (i) != (N); (i) += ((N) > (1) ? 1 : -1)) {
    while (t != -1 and o1[t + 1] != o1[i]) {
      t = fv[t];
    }
    if (o1[t + 1] == o1[i]) t++;
    fv[i] = t;
    ;
  }
  t = -1;
  for (int(i) = 0; (i) < (M); (i)++) {
    while (t != -1 and o1[t + 1] != o2[i]) {
      t = fv[t];
    }
    if (o1[t + 1] == o2[i]) t++;
    if (t == N - 1) return true;
  }
  return false;
}
int32_t main() {
  do {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  } while (0);
  int N;
  cin >> N;
  vint i1(N), i2(N);
  bool hs0 = false;
  for (int(i) = 0; (i) < (N); (i)++) {
    cin >> i1[i];
    hs0 |= (!i1[i]);
  }
  for (int(i) = 0; (i) < (N); (i)++) {
    cin >> i2[i];
  }
  if (!hs0) {
    if (i1 == i2) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
    return 0;
  }
  int id1, id2;
  id1 = id2 = 0;
  for (int(i) = 0; (i) < (N); (i)++) {
    if (i1[i]) o1[id1++] = i1[i];
    if (i2[i]) o2[id2++] = i2[i];
  }
  for (int(i) = 0; (i) < (id2); (i)++) o2[i + id2] = o2[i];
  if (kmp(id1, id2 * 2))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
