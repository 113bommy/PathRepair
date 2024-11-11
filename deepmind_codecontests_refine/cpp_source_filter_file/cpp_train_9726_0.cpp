#include <bits/stdc++.h>
using namespace std;
struct result {
  long long my, his;
  bool win;
  bool operator<(const result& r) const {
    if (!win && r.win) return true;
    if (win && !r.win) return false;
    if (my < r.my) return true;
    if (my > r.my) return false;
    return his < r.his;
  }
};
int n;
vector<int> score;
vector<result> res;
vector<vector<int> > adj;
vector<string> words;
const int INF = 100000000;
void rec(int v) {
  if (res[v].my >= 0) return;
  res[v].win = false;
  res[v].my = 0;
  res[v].his = 0;
  for (size_t i = 0; i < adj[v].size(); i++) {
    int u = adj[v][i];
    rec(u);
    result ch = res[u];
    swap(ch.his, ch.my);
    ch.win = !ch.win;
    ch.my += score[u];
    if (res[v] < ch) res[v] = ch;
  }
}
int calcScore(const string& s) {
  int res = 0, maxv = 0;
  for (size_t i = 0; i < s.length(); ++i) {
    int v = s[i] - 'a' + 1;
    maxv = max(v, maxv);
    res += v;
  }
  return res * maxv;
}
int main() {
  cout << fixed;
  cout.precision(9);
  map<string, int> count;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    set<string> curset;
    for (size_t i = 0; i < s.length(); ++i)
      for (size_t j = i; j < s.length(); ++j) {
        string subs = s.substr(i, j - i + 1);
        curset.insert(subs);
      }
    for (set<string>::const_iterator it = curset.begin(); it != curset.end();
         ++it) {
      count[*it]++;
    }
  }
  n = count.size() + 1;
  score.resize(n);
  res.resize(n);
  words.resize(n);
  words[0] = "";
  for (int i = 0; i < n; i++) {
    res[i].my = -1;
  }
  map<string, int>& word2id = count;
  int i = 1;
  for (map<string, int>::iterator it = count.begin(); it != count.end(); ++it) {
    score[i] = calcScore(it->first) + it->second;
    it->second = i;
    words[i] = it->first;
    ++i;
  }
  adj.resize(n);
  for (int i = 0; i < n; i++) {
    for (char c = 'a'; c <= 'z'; c++) {
      string s = words[i] + c;
      map<string, int>::const_iterator it = word2id.find(s);
      if (it != word2id.end()) {
        adj[i].push_back(it->second);
      }
      s = c + words[i];
      it = word2id.find(s);
      if (it != word2id.end()) {
        adj[i].push_back(it->second);
      }
    }
  }
  rec(0);
  cout << (res[0].win ? "First" : "Second") << "\n";
  cout << res[0].my << " " << res[0].his << endl;
  return 0;
}
