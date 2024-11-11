#include <bits/stdc++.h>
using namespace std;
template <class T>
void dbs(string str, T t) {
  cerr << str << " : " << t << "\n";
}
template <class T, class... S>
void dbs(string str, T t, S... s) {
  int idx = str.find(',');
  cerr << str.substr(0, idx) << " : " << t << ",";
  dbs(str.substr(idx + 1), s...);
}
template <class S, class T>
ostream& operator<<(ostream& os, const pair<S, T>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class T>
ostream& operator<<(ostream& os, const set<T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class S, class T>
ostream& operator<<(ostream& os, const map<S, T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class T>
void prc(T a, T b) {
  cerr << "[";
  for (T i = a; i != b; ++i) {
    if (i != a) cerr << ", ";
    cerr << *i;
  }
  cerr << "]\n";
}
struct trie {
  int nnodes;
  vector<vector<int> > T, S;
  trie() {
    nnodes = 1;
    T.push_back(vector<int>(2, -1));
    S.push_back(vector<int>(2, 1000000007));
  }
  void insert(int x) {
    int node = 0;
    for (int i = 19; i >= 0; i--) {
      int bit = (x >> i) & 1;
      if (T[node][bit] == -1) {
        T[node][bit] = nnodes++;
        T.push_back(vector<int>(2, -1));
        S.push_back(vector<int>(2, 1000000007));
      }
      S[node][bit] = min(S[node][bit], x);
      node = T[node][bit];
    }
  }
  int query(int x, int s) {
    int node = 0;
    int ret = 0;
    for (int i = 19; i >= 0; i--) {
      int bit = (x >> i) & 1;
      bit = 1 - bit;
      if (T[node][bit] != -1 && S[node][bit] <= s) {
        ret += (1 << i);
        node = T[node][bit];
      } else if (T[node][1 - bit] != -1 && S[node][1 - bit] <= s) {
        node = T[node][1 - bit];
      } else
        return -1;
    }
    return ret;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int q;
  cin >> q;
  int lim = sqrt(100000);
  trie tr[lim + 1];
  vector<bool> mark(100009);
  while (q--) {
    int ch;
    cin >> ch;
    if (ch == 1) {
      int x;
      cin >> x;
      for (long long int i = (long long int)(1); i <= (long long int)(lim); i++)
        if (x % i == 0) tr[i].insert(x);
      mark[x] = 1;
    } else {
      int x, k, s;
      cin >> x >> k >> s;
      s -= x;
      if (x % k != 0) {
        cout << -1 << "\n";
        continue;
      }
      if (k > lim) {
        int ans = -1;
        int maxx = -1;
        for (int i = k; i <= s; i += k)
          if (mark[i]) {
            if (i ^ x > maxx) {
              maxx = i ^ x;
              ans = i;
            }
          }
        cout << ans << "\n";
      } else {
        int ans = tr[k].query(x, s);
        if (ans == -1)
          cout << ans << "\n";
        else
          cout << (ans ^ x) << "\n";
      }
    }
  }
}
