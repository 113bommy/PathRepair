#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ldb = long double;
struct Node {
  Node* to[26];
  int cnt = 0;
};
Node* root[26];
int ans = 0;
bool used = 0;
set<string> words;
void make_branch(Node* v, const string& word, int pos) {
  if (!used) ++v->cnt;
  if (pos == word.size()) return;
  v->to[word[pos] - 'a'] = new Node();
  make_branch(v->to[word[pos] - 'a'], word, pos + 1);
}
int check_branch(Node* v, const string& word, int pos, int already) {
  if (!used) ++v->cnt;
  if (pos == word.size()) {
    bool fl = false;
    for (int i = 0; i < 26; ++i) {
      if (v->to[i] != nullptr) {
        fl = true;
        break;
      }
    }
    if (fl) {
      return already + 1;
    } else {
      return 1;
    }
  }
  if (v->to[word[pos] - 'a'] != nullptr) {
    return check_branch(v->to[word[pos] - 'a'], word, pos + 1, already + 1);
  } else {
    bool fl = false;
    for (int i = 0; i < 26; ++i) {
      if (v->to[i] != nullptr) {
        fl = true;
        break;
      }
    }
    v->to[word[pos] - 'a'] = new Node();
    make_branch(v->to[word[pos] - 'a'], word, pos + 1);
    if (fl) {
      return already + (int)word.size() - pos + 1;
    } else {
      return 1 + (int)word.size() - pos;
    }
  }
}
int trie(Node* v, const string& word, int pos) {
  if (pos == word.size()) {
    if (!used) ++v->cnt;
    return 0;
  }
  if (!used) ++v->cnt;
  if (v->to[word[pos] - 'a'] == nullptr) {
    v->to[word[pos] - 'a'] = new Node();
    make_branch(v->to[word[pos] - 'a'], word, pos + 1);
    return (int)word.size() - pos;
  }
  if (v->cnt == 2 && !used || used && v->cnt == 1) {
    return check_branch(v->to[word[pos] - 'a'], word, pos + 1, 0);
  } else {
    return trie(v->to[word[pos] - 'a'], word, pos + 1) + 1;
  }
}
int get_ans(const string& s, int l, int r) {
  string word;
  used = false;
  for (int i = l; i < r; ++i) {
    word += s[i];
  }
  if (words.find(word) != words.end())
    used = true;
  else
    words.insert(word);
  return trie(root[word[0] - 'a'], word, 1) + 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  for (int i = 0; i < 26; ++i) {
    root[i] = new Node();
  }
  while (getline(cin, s)) {
    for (int i = 0; i < s.size(); ++i) {
      if (!isalpha(s[i])) {
        ++ans;
        continue;
      }
      int l = i;
      while (i < s.size() && s[i] != ' ' && s[i] != '.' && s[i] != ',' &&
             s[i] != '?' && s[i] != '!' && s[i] != '\'' && s[i] != '-') {
        ++i;
      }
      int add = get_ans(s, l, i);
      ans += add;
      --i;
    }
    ++ans;
  }
  cout << ans;
}
