#include <bits/stdc++.h>
using namespace std;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using max_heap = priority_queue<T>;
template <class T>
ostream &operator<<(ostream &os, min_heap<T> H) {
  while (!H.empty()) {
    os << H.top() << " ";
    H.pop();
  }
  os << endl;
  return os << "";
}
template <class T>
ostream &operator<<(ostream &os, max_heap<T> H) {
  while (!H.empty()) {
    os << H.top() << " ";
    H.pop();
  }
  os << endl;
  return os << "";
}
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P) {
  return os << P.first << " " << P.second;
}
template <class T>
ostream &operator<<(ostream &os, vector<T> arr) {
  for (long long i = 0; i < (long long)arr.size(); i++) {
    os << arr[i] << " ";
  }
  return os << "";
}
template <class T>
ostream &operator<<(ostream &os, vector<vector<T>> matrix) {
  os << endl;
  for (long long i = 0; i < (long long)matrix.size(); i++) {
    for (long long j = 0; j < (long long)matrix[i].size(); j++) {
      os << matrix[i][j] << " ";
    }
    os << endl;
  }
  return os << "";
}
template <class T>
ostream &operator<<(ostream &os, set<T> S) {
  for (auto s : S) {
    os << s << " ";
  }
  return os << "";
}
template <class T>
ostream &operator<<(ostream &os, multiset<T> S) {
  for (auto s : S) {
    os << s << " ";
  }
  return os << "";
}
template <class L, class R>
ostream &operator<<(ostream &os, map<L, R> M) {
  os << endl;
  for (auto m : M) {
    os << m << endl;
  }
  return os << "";
}
template <class L, class R>
ostream &operator<<(ostream &os, multimap<L, R> M) {
  os << endl;
  for (auto m : M) {
    os << m << endl;
  }
  return os << "";
}
void solve() {
  long long N, K;
  cin >> N >> K;
  cout << "? ";
  for (long long i = 2; i <= K + 1; i++) {
    cout << i << " ";
  }
  cout << endl;
  long long pos, val;
  cin >> pos >> val;
  long long type = -1;
  vector<long long> state(N + 1);
  for (long long i = 2; i <= N; i++) {
    if (i != pos) {
      cout << "? ";
      for (long long j = 2; j <= K + 1; j++) {
        if (j == i) {
          cout << 1 << " ";
        } else {
          cout << j << " ";
        }
      }
      cout << endl;
      long long new_pos, new_val;
      cin >> new_pos >> new_val;
      state[i] = (new_pos == pos);
      if (!state[i]) {
        if (new_val > val) {
          type = 0;
        } else {
          type = 1;
        }
      }
    }
  }
  if (type == -1) {
    cout << "? ";
    for (long long i = 2; i <= K + 1; i++) {
      if (i == pos) {
        cout << 1 << " ";
      } else {
        cout << i << " ";
      }
    }
    cout << endl;
    long long new_pos, new_val;
    cin >> new_pos >> new_val;
    if (new_val > val) {
      cout << "! " << 1 << endl;
    } else {
      cout << "! " << K << endl;
    }
  } else {
    long long cnt = 0;
    for (long long i = 2; i <= K + 1; i++) {
      if (i != pos) {
        if ((type) && state[i]) {
          cnt++;
        } else if ((!type) && (!state[i])) {
          cnt++;
        }
      }
    }
    cout << "! " << cnt + 1 << endl;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long no_of_testcases = 1;
  for (long long i = 1; i <= no_of_testcases; i++) {
    solve();
  }
  return 0;
}
