#include <bits/stdc++.h>
using namespace std;
template <typename T>
T min(T a, T b, T c) {
  return min(a, min(b, c));
}
template <typename T>
T max(T a, T b, T c) {
  return max(a, max(b, c));
}
vector<pair<long long, long long>> traverse = {
    {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
void read(string& s) {
  s.clear();
  cin >> s;
}
template <typename T>
void read(vector<T>& arr, long long N) {
  arr.clear();
  arr.resize(N);
  for (long long i = 0; i < N; i++) cin >> arr[i];
}
template <typename T>
void read(vector<pair<T, T>>& arr, long long N) {
  arr.clear();
  arr.resize(N);
  for (long long i = 0; i < (long long)arr.size(); i++)
    cin >> arr[i].first >> arr[i].second;
}
template <typename T>
void read(vector<vector<T>>& arr, long long N, long long M) {
  arr.clear();
  arr.resize(N, vector<T>(M));
  for (long long i = 0; i < N; i++) {
    for (long long j = 0; j < M; j++) cin >> arr[i][j];
  }
}
template <typename T>
void print(vector<T>& arr) {
  for (auto it : arr) cout << it << ' ';
  cout << endl;
}
template <typename T>
void print(vector<pair<T, T>>& arr) {
  for (auto it : arr) cout << it.first << ' ' << it.second << endl;
}
template <typename T>
void print(vector<vector<T>>& arr) {
  for (auto it : arr) {
    for (auto ut : it) cout << ut << ' ';
    cout << endl;
  }
  cout << endl;
}
struct searchpair {
  vector<long long> A;
  void init(vector<pair<long long, long long>>& arr) {
    A.clear();
    for (long long i = 0; i < (long long)arr.size(); i++) {
      A.push_back(arr[i].first);
    }
  }
  long long _first(long long val) {
    auto it = lower_bound(A.begin(), A.end(), val);
    if (it == A.end()) return -1;
    return it - A.begin();
  }
};
bool lexi(string& s1, string& s2) {
  long long I = s1.size(), J = s2.size(), i = 0, j = 0;
  while (i < I and j < J) {
    if (s1[i] > s2[j]) return true;
    if (s1[i] < s2[j]) return false;
    i++;
    j++;
  }
  if (I >= J) return true;
  return false;
}
struct uf {
  vector<long long> par, size;
  void init(long long N) {
    par.resize(N, -1);
    size.resize(N, 1);
  }
  long long root(long long a) {
    if (par[a] == -1) return a;
    return par[a] = root(par[a]);
  }
  void unite(long long a, long long b) {
    a = root(a);
    b = root(b);
    if (a == b) return;
    if (size[a] < size[b]) {
      par[a] = b;
      size[b] += size[a];
    } else {
      par[b] = a;
      size[a] += size[b];
    }
  }
  bool same(long long a, long long b) {
    if (root(a) == root(b)) return true;
    return false;
  }
};
struct seg_tree {
  vector<long long> make;
  long long siz;
  vector<long long> arr;
  void init(vector<long long>& a, bool max, bool range) {
    arr.clear();
    make.clear();
    arr = a;
    siz = arr.size();
    make.resize(4 * siz);
    if (max)
      build_max(0, 0, siz - 1);
    else if (range)
      build_range(0, 0, siz - 1);
  }
  long long get_max(long long L, long long R) {
    return Get_max(0, 0, siz - 1, L, R);
  }
  void update_max(long long index, long long val) {
    Update_max(0, 0, siz - 1, index, val);
    return;
  }
  long long get_sum(long long L, long long R) {
    return Get_sum(0, 0, siz - 1, L, R);
  }
  void update_range(long long index, long long add) {
    Update_range(0, 0, siz - 1, index, add);
    return;
  }
  long long build_range(long long ind, long long L, long long R) {
    if (L == R) {
      make[ind] = arr[L];
      return make[ind];
    } else {
      long long mid = (L + R) / 2;
      long long a = build_range(2 * ind + 1, L, mid);
      long long b = build_range(2 * ind + 2, mid + 1, R);
      make[ind] = a + b;
      return make[ind];
    }
  }
  long long Get_sum(long long ind, long long L, long long R, long long Left,
                    long long Right) {
    if (L > Right or R < Left) return 0;
    if (Left <= L and R <= Right) return make[ind];
    long long mid = (L + R) / 2;
    long long a = Get_sum(2 * ind + 1, L, mid, Left, Right);
    long long b = Get_sum(2 * ind + 2, mid + 1, R, Left, Right);
    return a + b;
  }
  void Update_range(long long ind, long long L, long long R, long long index,
                    long long add) {
    if (L == R) {
      make[ind] += add;
      arr[index] += add;
    } else {
      long long mid = (L + R) / 2;
      if (L <= index and index <= R) {
        Update_range(2 * ind + 1, L, mid, index, add);
      } else {
        Update_range(2 * ind + 2, mid + 1, R, index, add);
      }
      make[ind] = make[2 * ind + 1] + make[2 * ind + 2];
    }
  }
  long long build_max(long long ind, long long L, long long R) {
    if (L == R) {
      make[ind] = arr[L];
      return make[ind];
    } else {
      long long mid = (L + R) / 2;
      return make[ind] = max(build_max(2 * ind + 1, L, mid),
                             build_max(2 * ind + 2, mid + 1, R));
    }
  }
  long long Get_max(long long ind, long long L, long long R, long long Left,
                    long long Right) {
    if (R < Left or L > Right) return -1e15;
    if (Left <= L and R <= Right) return make[ind];
    long long mid = (L + R) / 2;
    return max(Get_max(2 * ind + 1, L, mid, Left, Right),
               Get_max(2 * ind + 2, mid + 1, R, Left, Right));
  }
  long long Update_max(long long ind, long long L, long long R, long long index,
                       long long val) {
    if (L == R) {
      arr[index] = val;
      make[ind] = val;
      return val;
    } else {
      long long mid = (L + R) / 2;
      if (L <= index and index <= mid) {
        make[ind] = Update_max(2 * ind + 1, L, mid, index, val);
      } else {
        make[ind] = Update_max(2 * ind + 2, mid + 1, R, index, val);
      }
      make[ind] = max(make[2 * ind + 1], make[2 * ind + 2]);
      return make[ind];
    }
  }
};
static bool comp(pair<long long, long long>& a, pair<long long, long long>& b) {
  if (a.first < b.first) return true;
  if (a.first == b.first) {
    if (a.second < b.second) return true;
  }
  return false;
}
static bool comp1(pair<long long, long long>& a,
                  pair<long long, long long>& b) {
  if (a.first > b.first) return true;
  if (a.first == b.first) {
    if (a.second < b.second) return true;
  }
  return false;
}
long long Max = 1e18 + 10, Min = -1e16;
long long N, M, K;
long long mod = 1e9;
vector<long long> arr;
vector<long long> brr;
void solve() {
  cin >> N;
  read(arr, N);
  read(brr, N);
  vector<long long> t1(N + 1);
  for (long long i = 1; i <= N; i++) {
    t1[brr[i - 1]] = i;
  }
  vector<long long> t2(N + 1);
  for (long long i = 1; i <= N; i++) {
    t2[i] = t1[arr[i - 1]];
  }
  long long ind = N + 1;
  for (long long i = 2; i <= N; i++) {
    if (t2[i] > t2[i - 1]) continue;
    ind = i;
    break;
  }
  cout << N - ind + 1 << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  auto start_time = chrono::high_resolution_clock::now();
  bool test = 0;
  if (!test)
    solve();
  else {
    long long tt;
    cin >> tt;
    while (tt--) solve();
  }
  auto end_time = chrono::high_resolution_clock::now();
  return 0;
}
