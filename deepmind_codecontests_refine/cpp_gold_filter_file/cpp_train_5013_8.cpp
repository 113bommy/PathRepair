#include <bits/stdc++.h>
using namespace std;
long long t, pos, mx, cnt[700], printed, noans;
string s;
map<long long, vector<long long> > m;
vector<long long> ans;
set<char> ss;
void chk() {
  for (int i = 1; i < ans.size(); i++) {
    if (abs(ans[i] - ans[i - 1]) == 1) {
      noans++;
      return;
    }
  }
  for (auto it : ans) cout << char(it + 'a');
  cout << endl;
  printed = 1;
  return;
}
void odd1() {
  ans.clear();
  reverse(s.begin(), s.end());
  for (int i = 0; i < s.size(); i = i + 2) {
    for (int j = 0; j < cnt[int(s[i] - 'a')]; j++) {
      ans.push_back(int(s[i] - 'a'));
    }
  }
  for (int i = 1; i < s.size(); i = i + 2) {
    for (int j = 0; j < cnt[int(s[i] - 'a')]; j++) {
      ans.push_back(int(s[i] - 'a'));
    }
  }
  chk();
  reverse(s.begin(), s.end());
}
void odd2() {
  ans.clear();
  for (int i = 0; i < s.size(); i = i + 2) {
    for (int j = 0; j < cnt[int(s[i] - 'a')]; j++) {
      ans.push_back(int(s[i] - 'a'));
    }
  }
  for (int i = 1; i < s.size(); i = i + 2) {
    for (int j = 0; j < cnt[int(s[i] - 'a')]; j++) {
      ans.push_back(int(s[i] - 'a'));
    }
  }
  chk();
}
void even1() {
  m.clear();
  ans.clear();
  reverse(s.begin(), s.end());
  for (int i = 1; i < s.size(); i = i + 2) {
    for (int j = 0; j < cnt[int(s[i] - 'a')]; j++) {
      ans.push_back(int(s[i] - 'a'));
    }
  }
  for (int i = 0; i < s.size(); i = i + 2) {
    for (int j = 0; j < cnt[int(s[i] - 'a')]; j++) {
      ans.push_back(int(s[i] - 'a'));
    }
  }
  chk();
  reverse(s.begin(), s.end());
}
void even2() {
  m.clear();
  ans.clear();
  for (int i = 1; i < s.size(); i = i + 2) {
    for (int j = 0; j < cnt[int(s[i] - 'a')]; j++) {
      ans.push_back(int(s[i] - 'a'));
    }
  }
  for (int i = 0; i < s.size(); i = i + 2) {
    for (int j = 0; j < cnt[int(s[i] - 'a')]; j++) {
      ans.push_back(int(s[i] - 'a'));
    }
  }
  chk();
}
void analy() {
  for (int i = 0; i < 500; i++) cnt[i] = 0;
  for (auto it : s) cnt[int(it - 'a')]++;
}
int main() {
  cin >> t;
  for (int k = 0; k < t; k++) {
    cin >> s;
    printed = noans = 0;
    sort(s.begin(), s.end());
    mx = s.back() - 'a';
    analy();
    pos = 0;
    ss.clear();
    ss = set<char>(s.begin(), s.end());
    s = string(ss.begin(), ss.end());
    odd1();
    if (printed) {
      continue;
    }
    odd2();
    if (printed) {
      continue;
    }
    even1();
    if (printed) {
      continue;
    }
    even2();
    if (printed) {
      continue;
    }
    cout << "No answer\n";
  }
}
