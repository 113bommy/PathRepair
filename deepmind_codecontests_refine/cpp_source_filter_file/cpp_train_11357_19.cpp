#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300;
struct KMP {
  vector<int> text, pat, lps;
  void init(const vector<int> &v1, const vector<int> &v2) {
    text = v1;
    pat = v2;
    lps.resize(v2.size());
    lps[0] = 0;
    for (int i = 1; i < pat.size(); i++) {
      int len = lps[i - 1];
      while (true) {
        if (pat[len] == pat[i]) {
          lps[i] = len;
          break;
        }
        if (len == 0) {
          lps[i] = 0;
          break;
        }
        len = lps[len];
      }
    }
  }
  int match(int pos) {
    int i = pos, j = 0;
    while (i < text.size() && j < pat.size()) {
      if (text[i] == pat[j]) {
        i++;
        j++;
      } else if (j == 0) {
        i++;
      } else {
        j = lps[j - 1];
      }
    }
    if (j == pat.size()) return i;
    return -1;
  }
} kmp;
int len[MAXN + 5], cnt, L;
map<string, int> trans;
vector<int> text;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    string str;
    cin >> str;
    auto it = trans.find(str);
    if (it == trans.end()) {
      trans.emplace(str, ++cnt);
      len[cnt] = str.size();
    }
    text.push_back(trans[str]);
    L += str.size();
  }
  L += N - 1;
  int ans = L;
  for (int i = 0; i < text.size(); i++) {
    int profit = 0;
    vector<int> pat;
    for (int j = i; j < text.size(); j++) {
      int cost = L, occ = 0;
      profit += len[text[j]] - 1;
      if (i != j) profit++;
      pat.push_back(text[j]);
      kmp.init(text, pat);
      int pos = kmp.match(0);
      while (pos != -1) {
        cost -= profit;
        occ++;
        pos = kmp.match(pos);
      }
      if (occ > 1) {
        ans = min(ans, cost);
      }
    }
  }
  cout << ans << '\n';
}
