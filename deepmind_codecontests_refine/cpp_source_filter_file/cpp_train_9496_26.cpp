#include <bits/stdc++.h>
using namespace std;
const int hsize = 'z' - 'a' + 1;
void add(vector<int>& hist, const string& s) {
  for (int i = 0; i < s.length(); i++) hist[s[i] - 'a']++;
}
vector<int> sub(const vector<int>& a, const vector<int>& b) {
  vector<int> res(hsize);
  for (int i = 0; i < hsize; i++) {
    res[i] = a[i] - b[i];
  }
  return res;
}
vector<int> mul(const vector<int>& a, const int b) {
  vector<int> res(hsize);
  for (int i = 0; i < hsize; i++) {
    res[i] = a[i] * b;
  }
  return res;
}
vector<string> ask(int l, int r) {
  cout << "? " << l << " " << r << endl;
  int n = r - l + 1;
  int cnt = n * (n + 1) / 2;
  vector<string> res(cnt);
  for (int i = 0; i < cnt; i++) cin >> res[i];
  return res;
}
string hist_to_str(const vector<int>& h) {
  string res;
  for (int j = 0; j < hsize; j++)
    if (h[j] > 0) res += string(h[j], 'a' + j);
  return res;
}
vector<string> substr_to_pairs(const vector<string> substr, int len) {
  vector<vector<int>> hists(len, vector<int>(hsize, 0));
  for (int i = 0; i < substr.size(); i++) {
    add(hists[substr[i].length() - 1], substr[i]);
  }
  vector<string> res;
  for (int i = 0; i < len / 2; i++) {
    vector<int> h = sub(mul(hists[0], i + 2), hists[len - i - 2]);
    for (int j = 0; j < res.size(); j++) {
      h[res[j][0] - 'a'] -= res.size() + 1 - j;
      h[res[j][1] - 'a'] -= res.size() + 1 - j;
    }
    res.push_back(hist_to_str(h));
  }
  if (len % 2 != 0) {
    vector<int> h = hists[0];
    for (int j = 0; j < res.size(); j++) {
      h[res[j][0] - 'a']--;
      h[res[j][1] - 'a']--;
    }
    res.push_back(hist_to_str(h));
  }
  return res;
}
char get_next(const string& s, const char c) { return s[0] == c ? s[1] : s[0]; }
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  if (n <= 3) {
    string s;
    for (int i = 1; i <= n; i++) {
      s += ask(i, i)[0];
    }
    cout << "! " << s << endl;
    return 0;
  }
  int len1 = n / 2;
  int len2 = (n % 2 == 0) ? len1 - 1 : n - len1;
  auto rep1 = substr_to_pairs(ask(1, n), n);
  auto rep2 = substr_to_pairs(ask(1, len1), len1);
  auto rep3 = substr_to_pairs(ask(n - len2 + 1, n), len2);
  vector<vector<pair<string, int>>> edges(n);
  string s(n, ' ');
  auto addEdges = [&](const vector<string>& prs, int l, int r) {
    int i = 0;
    while (l < r) {
      edges[l].push_back(make_pair(prs[i], r));
      edges[r].push_back(make_pair(prs[i], l));
      l++;
      r--;
      i++;
    }
    if (l == r) s[r] = prs[i][0];
  };
  addEdges(rep1, 0, n - 1);
  addEdges(rep2, 0, len1 - 1);
  addEdges(rep3, n - len2, n - 1);
  function<void(int)> dfs;
  dfs = [&](int v) {
    for (int i = 0; i < edges[v].size(); i++) {
      int np = edges[v][i].second;
      if (s[np] == ' ') {
        s[np] = get_next(edges[v][i].first, s[i]);
        dfs(np);
      }
    }
  };
  for (int i = 0; i < n; i++)
    if (s[i] != ' ') dfs(i);
  cout << "! " << s << endl;
  return 0;
}
