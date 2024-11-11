#include <bits/stdc++.h>
using namespace std;
struct Node {
  bool endWord;
  int cont;
  int childs[4];
  Node(bool endWord, int cont) : endWord(endWord), cont(cont) {}
  Node() : endWord(false), cont(0) {}
};
Node Trie[600005];
int size = 1;
void push(string cad) {
  int act = 0;
  for (int i = 0; i < cad.size(); i++) {
    if (Trie[act].childs[cad[i] - 'a'] != 0) {
      act = Trie[act].childs[cad[i] - 'a'];
    } else {
      Trie[act].childs[cad[i] - 'a'] = size++;
      act = Trie[act].childs[cad[i] - 'a'];
    }
  }
  Trie[act].endWord = true;
  Trie[act].cont++;
}
bool find(int node, int ind, string& cad, bool band) {
  if (ind >= cad.size()) return Trie[node].endWord;
  bool ans = false;
  if (band) {
    for (int i = 0; i < 3; i++) {
      if (i == cad[ind] - 'a') continue;
      if (Trie[node].childs[i] != 0)
        ans = ans || find(Trie[node].childs[i], ind + 1, cad, false);
    }
  }
  if (Trie[node].childs[cad[ind] - 'a'] != 0)
    ans = ans || find(Trie[node].childs[cad[ind] - 'a'], ind + 1, cad, band);
  return ans;
}
int n, m;
string s;
int main() {
  ;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s;
    push(s);
  }
  for (int i = 0; i < m; i++) {
    cin >> s;
    if (find(0, 0, s, true))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
