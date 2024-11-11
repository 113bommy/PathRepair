#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
inline istream &operator>>(istream &str, pair<T, U> &p) {
  return str >> p.first >> p.second;
}
template <class T, class U>
inline ostream &operator<<(ostream &str, pair<T, U> &p) {
  return str << p.first << " " << p.second << endl;
}
template <class T>
inline istream &operator>>(istream &str, vector<T> &a) {
  for (auto &i : a) str >> i;
  return str;
}
template <class T>
inline ostream &operator<<(ostream &str, vector<T> &a) {
  for (auto &i : a) cout << i << " ";
  cout << endl;
  return str;
}
template <class T, class U>
inline ostream &operator<<(ostream &str, map<T, U> &a) {
  for (auto &i : a) cout << i.first << " " << i.second << endl;
  return str;
}
class trie {
  struct node {
    vector<long long> next;
    long long cnt;
    node() {
      next.resize(26, 0);
      cnt = 0;
    }
  };
  vector<node> nodes;
  const long long head = 1, null = 0;

 public:
  trie() { nodes.resize(2); }
  void insert(const string &s) {
    long long curr = head;
    for (auto &i : s) {
      if (nodes[curr].next[i - 'a'] == null) {
        nodes[curr].next[i - 'a'] = nodes.size();
        nodes.push_back(node());
      }
      curr = nodes[curr].next[i - 'a'];
    }
    nodes[curr].cnt++;
  }
  template <typename T>
  long long query(const T &s) {
    long long curr = head, cnt = 0;
    for (auto &i : s) {
      if (curr == null) return cnt;
      cnt += nodes[curr].cnt;
      curr = nodes[curr].next[i - 'a'];
    }
    cnt += nodes[curr].cnt;
    return cnt;
  }
};
vector<long long> z_function(string &s) {
  long long n = s.size();
  vector<long long> z(n);
  for (long long i = 1, l = 0, r = 0; i < n; i++) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string given, givenr;
  cin >> given;
  givenr = given;
  reverse(givenr.begin(), givenr.end());
  long long n;
  cin >> n;
  string pat[n + 1];
  for (long long i = 0; i < n; ++i) {
    cin >> pat[i];
  }
  trie forward, backward;
  vector<long long> forz(given.size()), backz(given.size());
  for (long long i = 0; i < n; ++i) {
    if (pat[i].size() < 500) {
      forward.insert(pat[i]);
      reverse(pat[i].begin(), pat[i].end());
      backward.insert(pat[i]);
    } else {
      string temp = pat[i] + given;
      vector<long long> sol = z_function(temp);
      for (long long j = 0; j < given.size(); ++j) {
        if (sol[j + pat[i].size()] >= pat[i].size()) forz[j] += 1;
      }
      reverse(pat[i].begin(), pat[i].end());
      temp = pat[i] + givenr;
      sol = z_function(temp);
      for (long long j = 0; j < given.size(); ++j) {
        if (sol[j + pat[i].size()] >= pat[i].size()) backz[j] += 1;
      }
    }
  }
  reverse(backz.begin(), backz.end());
  long long ans = 0;
  deque<char> lets;
  for (long long i = 0; i < given.size(); ++i) {
    lets.push_front(given[i]);
    backz[i] += backward.query(lets);
  }
  lets.clear();
  for (long long i = given.size() - 1; i >= 0; --i) {
    lets.push_front(given[i]);
    forz[i] += forward.query(lets);
  }
  for (long long i = 1; i < given.size(); ++i) {
    ans += forz[i] * backz[i - 1];
  }
  cout << ans << endl;
  return 0;
}
