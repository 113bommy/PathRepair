#include <bits/stdc++.h>
using namespace std;
template <int C>
struct PersistentStringTrie {
  PersistentStringTrie* nex[C];
  signed long long v;
  int mp(char c) {
    if (c >= 'a' && c <= 'z') return c - 'a';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 26;
    assert(0);
    return 0;
  }
  PersistentStringTrie() {
    v = -1;
    for (int i = 0; i < C; i++) nex[i] = NULL;
  }
  PersistentStringTrie(PersistentStringTrie* pst) {
    v = pst->v;
    for (int i = 0; i < C; i++) nex[i] = pst->nex[i];
  }
  PersistentStringTrie* set(string& s, signed long long val, int pos = 0) {
    PersistentStringTrie* pst = new PersistentStringTrie(this);
    if (pos >= s.size()) {
      pst->v = val;
    } else {
      int c = mp(s[pos]);
      if (!nex[c]) nex[c] = new PersistentStringTrie();
      pst->nex[c] = nex[c]->set(s, val, pos + 1);
    }
    return pst;
  }
  signed long long get(string& s, int pos = 0) {
    if (pos >= s.size()) return v;
    int c = mp(s[pos]);
    if (!nex[c]) return -1;
    return nex[c]->get(s, pos + 1);
  }
};
struct PersistentBinarySumTrie {
  PersistentBinarySumTrie* nex[2];
  signed long long v;
  PersistentBinarySumTrie() {
    nex[0] = nex[1] = NULL;
    v = 0;
  }
  PersistentBinarySumTrie(PersistentBinarySumTrie* pbst) {
    nex[0] = pbst->nex[0];
    nex[1] = pbst->nex[1];
    v = pbst->v;
  }
  PersistentBinarySumTrie* add(signed long long s, signed long long val,
                               int pos = 60) {
    PersistentBinarySumTrie* pbst = new PersistentBinarySumTrie(this);
    pbst->v += val;
    if (pos >= 0) {
      int c = (s >> pos) & 1;
      if (!nex[c]) nex[c] = new PersistentBinarySumTrie();
      pbst->nex[c] = nex[c]->add(s, val, pos - 1);
    }
    return pbst;
  }
  signed long long get(signed long long s, int pos = 60) {
    if (pos < 0) return 0;
    int c = (s >> pos) & 1;
    if (c)
      return (nex[0] ? nex[0]->v : 0) + (nex[1] ? nex[1]->get(s, pos - 1) : 0);
    else
      return (nex[0] ? nex[0]->get(s, pos - 1) : 0);
  }
};
int Q;
PersistentStringTrie<26>* st[101010];
PersistentBinarySumTrie* bst[101010];
string OP, A;
int X;
void solve() {
  int i, j, k, l, r, x, y;
  string s;
  st[0] = new PersistentStringTrie<26>();
  bst[0] = new PersistentBinarySumTrie();
  cin >> Q;
  for (i = 1; i <= Q; i++) {
    cin >> OP;
    if (OP == "set") {
      cin >> A >> X;
      x = st[i - 1]->get(A);
      st[i] = st[i - 1]->set(A, X);
      if (x >= 0) {
        bst[i] = bst[i - 1]->add(x, -1)->add(X, 1);
      } else {
        bst[i] = bst[i - 1]->add(X, 1);
      }
    }
    if (OP == "remove") {
      cin >> A;
      x = st[i - 1]->get(A);
      st[i] = st[i - 1]->set(A, -1);
      if (x >= 0) {
        bst[i] = bst[i - 1]->add(x, -1);
      } else {
        bst[i] = bst[i - 1];
      }
    }
    if (OP == "undo") {
      cin >> X;
      st[i] = st[i - X - 1];
      bst[i] = bst[i - X - 1];
    }
    if (OP == "query") {
      st[i] = st[i - 1];
      bst[i] = bst[i - 1];
      cin >> A;
      x = st[i]->get(A);
      if (x < 0)
        cout << -1 << endl;
      else
        cout << bst[i]->get(x) << endl;
    }
  }
}
int main(int argc, char** argv) {
  string s;
  int i;
  if (argc == 1) ios::sync_with_stdio(false), cin.tie(0);
  for (i = 0; i < (argc - 1); i++) s += argv[i + 1], s += '\n';
  for (i = 0; i < (s.size()); i++) ungetc(s[s.size() - 1 - i], stdin);
  cout.tie(0);
  solve();
  return 0;
}
