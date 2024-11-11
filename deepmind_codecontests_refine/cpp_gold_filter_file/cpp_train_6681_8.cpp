#include <bits/stdc++.h>
using namespace std;
struct trie_node {
  int term = 0;
  trie_node *go_to[26];
  trie_node *suff = nullptr;
  trie_node() { fill(go_to, go_to + 26, nullptr); }
};
void add(trie_node *root, string &s) {
  auto n = root;
  for (int i = 0; i < (int)s.size(); i++) {
    if (!n->go_to[s[i] - 'a']) {
      n->go_to[s[i] - 'a'] = new trie_node();
    }
    n = n->go_to[s[i] - 'a'];
  }
  n->term++;
}
void print(trie_node *n, string s = "") {
  if (!n) return;
  cout << n << ' ' << s << endl;
  for (int i = 0; i < 26; i++) {
    char c = 'a' + i;
    print(n->go_to[i], s + c);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cout.tie(0);
  string t;
  cin >> t;
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  trie_node *acho_trie = new trie_node();
  for (int i = 0; i < n; i++) {
    add(acho_trie, s[i]);
  }
  queue<trie_node *> Q;
  for (int i = 0; i < 26; i++) {
    if (!acho_trie->go_to[i]) {
      acho_trie->go_to[i] = acho_trie;
    } else {
      acho_trie->go_to[i]->suff = acho_trie;
      Q.push(acho_trie->go_to[i]);
    }
  }
  while (!Q.empty()) {
    trie_node *cur = Q.front();
    cur->term += cur->suff->term;
    Q.pop();
    for (int i = 0; i < 26; i++) {
      if (!cur->go_to[i]) {
        cur->go_to[i] = cur->suff->go_to[i];
      } else {
        cur->go_to[i]->suff = cur->suff->go_to[i];
        Q.push(cur->go_to[i]);
      }
    }
  }
  trie_node *cur = acho_trie;
  int sz = (int)t.size();
  vector<int> ends(sz);
  for (int i = 0; i < sz; i++) {
    cur = cur->go_to[t[i] - 'a'];
    ends[i] = cur->term;
  }
  t += '#';
  sz++;
  vector<int> ordered(sz);
  vector<int> class_(sz);
  for (int i = 0; i < sz - 1; i++) {
    ordered[i] = i;
    class_[i] = t[i] - 'a' + 1;
  }
  ordered[sz - 1] = sz - 1;
  class_[sz - 1] = 0;
  int class_num = 27;
  for (int len = 1; len < sz * 2; len <<= 1) {
    for (int k = 1; k >= 0; k--) {
      vector<int> cl_sz(class_num);
      for (int i = 0; i < sz; i++) {
        cl_sz[class_[i]]++;
      }
      for (int i = 1; i < class_num; i++) {
        cl_sz[i] += cl_sz[i - 1];
      }
      vector<int> new_ordered(sz);
      for (int i = sz - 1; i >= 0; i--) {
        int g = (ordered[i] + k * len) % sz;
        int pos = --cl_sz[class_[g]];
        new_ordered[pos] = ordered[i];
      }
      ordered = new_ordered;
    }
    vector<int> new_class(sz);
    pair<int, int> prev_class = {-1, -1};
    class_num = 0;
    for (int i = 0; i < sz; i++) {
      pair<int, int> cur_class;
      cur_class.first = class_[ordered[i]];
      cur_class.second = class_[(ordered[i] + len) % sz];
      if (cur_class != prev_class) {
        new_class[ordered[i]] = class_num++;
      } else {
        new_class[ordered[i]] = class_num - 1;
      }
      prev_class = cur_class;
    }
    class_ = new_class;
  }
  ends.insert(ends.begin(), 0);
  vector<long long> suf_ends(sz);
  for (int i = 0; i < sz; i++) {
    suf_ends[i] = ends[ordered[i]];
  }
  for (int i = 1; i < sz; i++) {
    suf_ends[i] += suf_ends[i - 1];
  }
  suf_ends.push_back(suf_ends.back());
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    auto st = ordered.begin();
    auto fin = ordered.end();
    for (int j = 0; j < (int)s[i].size(); j++) {
      function<bool(int, char)> cmp1 = [&t, j, sz](int a, char b) {
        int pa = (a + j) % sz;
        return t[pa] < b;
      };
      function<bool(char, int)> cmp2 = [&t, j, sz](char a, int b) {
        int pb = (b + j) % sz;
        return a < t[pb];
      };
      st = lower_bound(st, fin, s[i][j], cmp1);
      fin = upper_bound(st, fin, s[i][j], cmp2);
    }
    int sti = st - ordered.begin();
    int fini = fin - ordered.begin() - 1;
    ans += suf_ends[fini] - suf_ends[sti - 1];
  }
  cout << ans << endl;
}
