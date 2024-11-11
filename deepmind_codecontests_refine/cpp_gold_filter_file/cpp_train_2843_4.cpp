#include <bits/stdc++.h>
using namespace std;
vector<int> sa;
vector<int> sa_;
vector<int> rk;
vector<int> rk_;
vector<int> lcp;
vector<int> lcp_;
vector<int> tmp;
string ALL;
string ALL_;
int allsz, k;
bool nowcalc = 0;
bool compare1(int i, int j) {
  if (rk[i] != rk[j]) {
    return rk[i] < rk[j];
  } else {
    int ri = (i + k < allsz) ? rk[i + k] : -1;
    int rj = (j + k < allsz) ? rk[j + k] : -1;
    return ri < rj;
  }
}
bool compare2(int i, int j) {
  if (rk_[i] != rk_[j]) {
    return rk_[i] < rk_[j];
  } else {
    int ri = (i + k < allsz) ? rk_[i + k] : -1;
    int rj = (j + k < allsz) ? rk_[j + k] : -1;
    return ri < rj;
  }
}
bool compare(int i, int j) {
  if (!nowcalc) {
    return compare1(i, j);
  } else {
    return compare2(i, j);
  }
}
void buildSA(string str, vector<int> &s, vector<int> &r, vector<int> &l) {
  s.resize(allsz + 1);
  r.resize(allsz + 1);
  l.resize(allsz + 1);
  tmp.resize(allsz + 1);
  for (int i = 0; i < allsz + 1; i++) {
    s[i] = i;
    r[i] = (i < allsz) ? str[i] : -1;
  }
  for (k = 1; k <= allsz; k *= 2) {
    int p = 0;
    if (!k) {
      for (int x = 1; x <= allsz; x++) {
        if (r[s[p]] != r[s[x]]) {
          sort(s.begin() + p, s.begin() + x, compare);
          p = x;
        }
      }
    }
    sort(s.begin() + p, s.end(), compare);
    tmp[s[0]] = 0;
    for (int i = 1; i <= allsz; i++) {
      tmp[s[i]] = tmp[s[i - 1]] + (compare(s[i - 1], s[i]) ? 1 : 0);
    }
    for (int i = 0; i < allsz + 1; i++) {
      r[i] = tmp[i];
    }
  }
  int h = 0;
  l[0] = 0;
  for (int i = 0; i < allsz; i++) {
    int j = s[r[i] - 1];
    if (h > 0) h--;
    while (i + h < allsz && j + h < allsz) {
      if (str[i + h] != str[j + h]) break;
      h++;
    }
    l[r[j]] = h;
  }
}
int main() {
  vector<int> pos, ls, a, b;
  cin >> ALL;
  string t;
  int fl = (int)ALL.length();
  ALL_.resize(fl);
  a.resize(fl);
  b.resize(fl);
  reverse_copy(ALL.begin(), ALL.end(), ALL_.begin());
  int m;
  cin >> m;
  int nowp = (int)ALL.length() + 1;
  for (int i = 0; i < m; i++) {
    pos.push_back(nowp);
    cin >> t;
    ALL += '$';
    ALL += t;
    reverse(t.begin(), t.end());
    ALL_ += '$';
    ALL_ += t;
    ls.push_back((int)t.length());
    nowp += ls[i] + 1;
  }
  allsz = (int)ALL.length();
  nowcalc = 0;
  buildSA(ALL, sa, rk, lcp);
  nowcalc = 1;
  buildSA(ALL_, sa_, rk_, lcp_);
  int ans = 0;
  for (int i = 0; i < m; i++) {
    if (ls[i] == 1) {
      continue;
    }
    fill(a.begin(), a.end(), 0);
    fill(b.begin(), b.end(), 0);
    int hoge = rk[pos[i]];
    int he = ls[i];
    while (he && hoge <= allsz) {
      if (sa[hoge] + he - 1 < fl) {
        a[sa[hoge] + he - 1] = max(a[sa[hoge] + he - 1], he);
      }
      he = min(he, lcp[hoge]);
      hoge++;
    }
    hoge = rk[pos[i]];
    he = ls[i];
    while (he && hoge >= 0) {
      if (sa[hoge] + he - 1 < fl) {
        a[sa[hoge] + he - 1] = max(a[sa[hoge] + he - 1], he);
      }
      hoge--;
      he = min(he, lcp[hoge]);
    }
    hoge = rk_[pos[i]];
    he = ls[i];
    while (he && hoge <= allsz) {
      if (sa_[hoge] + he - 1 < fl) {
        b[sa_[hoge] + he - 1] = max(b[sa_[hoge] + he - 1], he);
      }
      he = min(he, lcp_[hoge]);
      hoge++;
    }
    hoge = rk_[pos[i]];
    he = ls[i];
    while (he && hoge >= 0) {
      if (sa_[hoge] + he - 1 < fl) {
        b[sa_[hoge] + he - 1] = max(b[sa_[hoge] + he - 1], he);
      }
      hoge--;
      he = min(he, lcp_[hoge]);
    }
    for (int j = 0; j < fl - 1; j++) {
      a[j + 1] = max(a[j + 1], a[j]);
      b[j + 1] = max(b[j + 1], b[j]);
    }
    for (int j = 0; j < fl - 1; j++) {
      a[fl - j - 2] = max(a[fl - j - 2], a[fl - j - 1] - 1);
      b[fl - j - 2] = max(b[fl - j - 2], b[fl - j - 1] - 1);
    }
    for (int j = 0; j < fl - 1; j++) {
      if (a[j] && b[fl - j - 2] && a[j] + b[fl - j - 2] >= ls[i]) {
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
