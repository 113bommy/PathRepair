#include <bits/stdc++.h>
using namespace std;
struct Smail {
  int first, second, third;
};
Smail mail[1000500];
string s;
long long ans = 0;
vector<char> v;
void solution() {
  cin >> s;
  long long j = 0, BEGIN = 0, END = 0;
  memset(mail, 0, sizeof(mail));
  v.push_back('1');
  v.push_back('1');
  for (int i = (0); i <= (s.length() - 1); i++) {
    j++;
    char temp = s[i];
    if (temp >= 'a' && temp <= 'z') {
      mail[j].first = mail[j - 1].first + 1;
      mail[j].second = mail[j - 1].second + 2;
      mail[j].third = mail[j - 1].third;
    } else if (temp >= '0' && temp <= '9') {
      mail[j].first = mail[j - 1].first;
      mail[j].second = mail[j - 1].second + 2;
      mail[j].third = 0;
    } else if (temp == '_') {
      mail[j].first = mail[j - 1].first;
      mail[j].second = 0;
      mail[j].third = 0;
      BEGIN = 0;
      v.push_back(temp);
    } else if (temp == '@') {
      BEGIN = mail[j - 1].first;
      mail[j].first = 0;
      mail[j].second = -1;
      mail[j].third = 0;
      v.push_back(temp);
    } else if (temp == '.') {
      mail[j].third = mail[j - 1].second;
      mail[j].first = 0;
      mail[j].second = 0;
      v.push_back(temp);
    }
    if (mail[j].third > 0 && temp != '.' && v[v.size() - 1] == '.' &&
        v[v.size() - 2] == '@') {
      ans += BEGIN;
    }
  }
  cout << ans << endl;
};
int main() { solution(); }
