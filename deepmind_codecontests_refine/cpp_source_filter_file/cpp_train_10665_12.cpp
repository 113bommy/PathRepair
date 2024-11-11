#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 7;
int n, k;
struct trie {
  int Next[N][26];
  int h;
  trie() {
    memset(Next, -1, sizeof(Next));
    h = 1;
  }
  void insert(string s) {
    int cur = 0;
    for (int i = 0; i < s.size(); i++) {
      int id = s[i] - 'a';
      if (Next[cur][id] == -1) {
        Next[cur][id] = h++;
      }
      cur = Next[cur][id];
    }
  }
};
trie myTrie;
map<int, int> memo;
int canWin(int cur) {
  if (memo.find(cur) != memo.end()) {
    return memo[cur];
  }
  int win = false;
  for (int i = 0; i < 26; i++) {
    if (myTrie.Next[cur][i] != -1) {
      int v = myTrie.Next[cur][i];
      if (!canWin(v)) {
        win = true;
        break;
      }
    }
  }
  memo[cur] = win;
  return memo[cur];
}
int canLose(int cur) {
  if (cur == 0) return true;
  if (memo.find(cur) != memo.end()) {
    return memo[cur];
  }
  int lose = false;
  int canMove = false;
  for (int i = 0; i < 26; i++) {
    if (myTrie.Next[cur][i] != -1) {
      canMove = true;
      int v = myTrie.Next[cur][i];
      if (!canLose(v)) {
        lose = true;
        break;
      }
    }
  }
  if (!canMove) lose = true;
  memo[cur] = lose;
  return memo[cur];
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    myTrie.insert(s);
  }
  memo.clear();
  int win = canWin(0);
  memo.clear();
  int lose = canLose(0);
  if (!win) {
    cout << "Second" << endl;
  } else {
    if (lose)
      cout << "First" << endl;
    else {
      if (k % 2 == 0) {
        cout << "Second" << endl;
      } else {
        cout << "First" << endl;
      }
    }
  }
  return 0;
}
