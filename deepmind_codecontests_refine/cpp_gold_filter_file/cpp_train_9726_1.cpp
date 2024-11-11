#include <bits/stdc++.h>
using namespace std;
template <typename T>
void debug(T v, string delimiter = "\n") {
  for (__typeof(v.begin()) it = v.begin(), it_end = v.end(); it != it_end; it++)
    cout << *it << delimiter;
  cout << flush;
}
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
string ds = "SENW";
map<string, int> s2score;
int max_value(string& s) {
  int ret = 0;
  for (int i = 0, i_end = (int((int)(s.size()))); i < i_end; i++)
    ret = max(ret, s[i] - 'a' + 1);
  return ret;
}
int sum_value(string& s) {
  int ret = 0;
  for (int i = 0, i_end = (int((int)(s.size()))); i < i_end; i++)
    ret += s[i] - 'a' + 1;
  return ret;
}
vector<char> cand;
struct data_t {
  int win;
  long long p1, p2;
};
map<string, data_t> memo;
bool greater2(data_t& d1, data_t& d2) {
  if (d1.win != d2.win) return d1.win > d2.win;
  if (d1.p1 != d2.p1) return d1.p1 > d2.p1;
  return d1.p2 < d2.p2;
}
data_t dfs(string& str) {
  vector<string> cs;
  if (memo.count(str)) {
    return memo[str];
  }
  for (int i = 0, i_end = (int((int)(cand.size()))); i < i_end; i++) {
    cs.push_back(cand[i] + str);
    cs.push_back(str + cand[i]);
  }
  sort((cs).begin(), (cs).end());
  cs.erase(unique(cs.begin(), cs.end()), cs.end());
  data_t val = (data_t){-1, 0, 0};
  for (int i = 0, i_end = (int((int)(cs.size()))); i < i_end; i++) {
    string s = cs[i];
    if (s2score.count(s) == 0) continue;
    int score = s2score[s];
    data_t sub = dfs(s);
    sub.win = 1 - sub.win;
    swap(sub.p1, sub.p2);
    sub.p1 += score;
    if (greater2(sub, val)) {
      val = sub;
    }
  }
  if (val.win == -1) val.win = 0;
  return memo[str] = val;
}
int main(int argc, char** argv) {
  int n;
  cin >> n;
  vector<string> dic;
  vector<vector<string> > dic_sub;
  for (int i = 0, i_end = (int(n)); i < i_end; i++) {
    string s;
    cin >> s;
    vector<string> se;
    for (int j = 0; j < (int)(s.size()); j++) {
      for (int k = j; k < (int)(s.size()); k++) {
        se.push_back(s.substr(j, k - j + 1));
      }
    }
    sort((se).begin(), (se).end());
    se.erase(unique(se.begin(), se.end()), se.end());
    dic.push_back(s);
    dic_sub.push_back(se);
    for (int j = 0, j_end = (int((int)(se.size()))); j < j_end; j++)
      s2score[se[j]]++;
  }
  vector<string> all_sub;
  for (__typeof(s2score.begin()) it = s2score.begin(), it_end = s2score.end();
       it != it_end; it++)
    all_sub.push_back(it->first);
  for (int i = 0, i_end = (int((int)(all_sub.size()))); i < i_end; i++) {
    s2score[all_sub[i]] += max_value(all_sub[i]) * sum_value(all_sub[i]);
  }
  string s = "";
  cand.clear();
  for (char c = 'a'; c <= 'z'; c++) {
    if (s2score.count(string(1, c))) cand.push_back(c);
  }
  memo.clear();
  data_t ans = dfs(s);
  cout << (ans.win ? "First" : "Second") << endl;
  cout << ans.p1 << " " << ans.p2 << endl;
  return 0;
}
