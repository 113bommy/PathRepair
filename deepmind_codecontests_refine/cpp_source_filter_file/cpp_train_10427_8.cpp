#include <bits/stdc++.h>
using namespace std;
inline void boost() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
}
vector<pair<string, pair<int, int> > > words;
string s;
void doassign(string s) {
  if ((int)s.size() - 4 >= 0) {
    string buff = "";
    for (int i = (int)s.size() - 4; i < (int)s.size(); i++) buff += s[i];
    if (buff == "lios") {
      words.push_back(make_pair(buff, make_pair(0, 0)));
      return;
    }
    if (buff == "etra") {
      words.push_back(make_pair(buff, make_pair(1, 1)));
      return;
    }
  }
  if ((int)s.size() - 3 >= 0) {
    string buff = "";
    for (int i = (int)s.size() - 3; i < (int)s.size(); i++) buff += s[i];
    if (buff == "etr") {
      words.push_back(make_pair(buff, make_pair(1, 0)));
      return;
    }
  }
  if ((int)s.size() - 5 >= 0) {
    string buff = "";
    for (int i = (int)s.size() - 5; i < (int)s.size(); i++) buff += s[i];
    if (buff == "liala") {
      words.push_back(make_pair(buff, make_pair(0, 1)));
      return;
    }
  }
  if ((int)s.size() - 6 >= 0) {
    string buff = "";
    for (int i = (int)s.size() - 6; i < (int)s.size(); i++) buff += s[i];
    if (buff == "initis") {
      words.push_back(make_pair(buff, make_pair(2, 0)));
      return;
    }
    if (buff == "inites") {
      words.push_back(make_pair(buff, make_pair(2, 1)));
      return;
    }
  }
  cout << "NO";
  exit(0);
}
int main() {
  boost();
  getline(cin, s);
  for (int i = 0; i < (int)s.size(); i++) {
    string buff = "";
    int it = i;
    while (it < (int)s.size() && s[it] != ' ') buff += s[it], it++;
    i = it;
    doassign(buff);
  }
  if ((int)words.size() == 1) {
    cout << "YES";
    return 0;
  }
  int vrb, noun, main_tone = words[0].second.second;
  vrb = noun = 0;
  bool ok = 1;
  for (auto t : words) {
    if (t.second.second != main_tone) ok = 0;
    if (t.second.first == 0 && (noun || vrb)) ok = 0;
    if (t.second.first == 1) noun++;
    if (t.second.first == 1 && vrb) ok = 0;
    if (noun > 1) ok = 0;
    if (t.second.first == 2) vrb++;
    if (vrb && !noun) ok = 0;
  }
  if (ok)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
