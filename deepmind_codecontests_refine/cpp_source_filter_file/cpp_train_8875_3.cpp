#include <bits/stdc++.h>
using namespace std;
struct Node {
  int leaf;
  int link;
  int next[9];
  Node() {
    for (int i = 0; i < 9; ++i) {
      next[i] = 0;
    }
    leaf = link = 0;
  }
};
vector<Node> trie(1);
void insert(string &s) {
  int node = 0;
  for (char ch : s) {
    if (!trie[node].next[ch - '1']) {
      trie[node].next[ch - '1'] = trie.size();
      trie.emplace_back();
    }
    node = trie[node].next[ch - '1'];
  }
  trie[node].leaf = 1;
}
void build() {
  queue<int> q;
  for (int i = 0; i < 9; ++i) {
    if (trie[0].next[i]) {
      q.push(trie[0].next[i]);
    }
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int ch = 0; ch < 9; ++ch) {
      int v = trie[u].next[ch];
      if (v) {
        q.push(v);
        int &link = trie[v].link;
        link = trie[u].link;
        while (link && trie[link].next[ch] == 0) {
          link = trie[link].link;
        }
        if (trie[link].next[ch]) {
          link = trie[link].next[ch];
        }
        if (trie[link].leaf) {
          trie[v].leaf |= 2;
        }
      } else {
        trie[u].next[ch] = trie[trie[u].link].next[ch];
      }
    }
  }
}
int n;
string text;
vector<int> matches;
void find_matches(int u, int idx) {
  if (idx == text.size()) return;
  int v = trie[u].next[text[idx] - '1'];
  if (trie[v].leaf) {
    matches.emplace_back(idx);
  }
  find_matches(v, idx + 1);
}
void print(string &txt) {
  for (int i = 0; i < txt.size(); ++i) {
    cout << setw(2) << i << ' ';
  }
  cout << endl;
  for (char &c : txt) {
    cout << setw(2) << c << ' ';
  }
  cout << endl;
}
int x;
string t;
void brute(int sum) {
  if (sum > x) return;
  if (sum == x) {
    int ok = 1;
    for (int i = 0; i < t.size(); ++i) {
      int curr = 0;
      for (int j = i; j < t.size(); ++j) {
        curr += t[i] - '0';
        if (curr != sum && sum % curr == 0) {
          ok = 0;
        }
      }
    }
    if (ok) {
      insert(t);
    }
    return;
  }
  for (int i = 1; i <= 9; ++i) {
    t += (char)'0' + i;
    brute(sum + i);
    t.pop_back();
  }
}
string s;
vector<vector<int> > dp;
int f(int idx, int u) {
  if (idx == s.size()) return 0;
  int v = trie[u].next[s[idx] - '1'];
  int &ans = dp[idx][u];
  if (~ans) return ans;
  if (trie[v].leaf) {
    return ans = f(idx + 1, u) + 1;
  }
  return ans = min(f(idx + 1, u) + 1, f(idx + 1, v));
}
int main() {
  cin >> s;
  cin >> x;
  brute(0);
  build();
  dp = vector<vector<int> >(s.size(), vector<int>(trie.size(), -1));
  cout << f(0, 0) << endl;
  return 0;
}
