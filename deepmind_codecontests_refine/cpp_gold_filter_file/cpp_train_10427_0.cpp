#include <bits/stdc++.h>
using namespace std;
vector<string> words;
string texts[2][3] = {{"soil", "rte", "sitini"}, {"alail", "arte", "setini"}};
int getSex() {
  int sa = -1;
  int sb = -1;
  for (int i = int(0); i < int(words.size()); i++) {
    string cur = words[i];
    reverse((cur).begin(), (cur).end());
    for (int j = int(0); j < int(3); j++) {
      if (cur.find(texts[0][j]) == 0) sa = 0;
    }
    for (int j = int(0); j < int(3); j++) {
      if (cur.find(texts[1][j]) == 0) sb = 0;
    }
  }
  if (sb == 0 && sa == -1) return 1;
  if (sb == -1 && sa == 0) return 0;
  return -1;
}
bool isword() {
  if (words.size() != 1) return 0;
  bool ok = 0;
  string cur = words[0];
  reverse((cur).begin(), (cur).end());
  for (int i = int(0); i < int(2); i++)
    for (int j = int(0); j < int(3); j++)
      if (cur.find(texts[i][j]) == 0) ok = 1;
  return ok;
}
bool issentence(int sex) {
  int adj = 0;
  int nou = 0;
  int ver = 0;
  int i;
  for (i = 0; i < words.size(); i++) {
    string cur = words[i];
    reverse((cur).begin(), (cur).end());
    if (cur.find(texts[sex][0]) == 0) {
      adj++;
    } else
      break;
  }
  for (; i < words.size(); i++) {
    string cur = words[i];
    reverse((cur).begin(), (cur).end());
    if (cur.find(texts[sex][1]) == 0) {
      nou++;
    } else
      break;
  }
  for (; i < words.size(); i++) {
    string cur = words[i];
    reverse((cur).begin(), (cur).end());
    if (cur.find(texts[sex][2]) == 0) {
      ver++;
    } else
      break;
  }
  return (adj >= 0 && nou == 1 && ver >= 0 && i == words.size());
}
int main() {
  string line;
  words.clear();
  getline(cin, line);
  stringstream ss(line);
  while (ss >> line) words.push_back((line));
  int sx = getSex();
  if (isword() || (sx >= 0 && issentence(sx))) {
    cout << "YES" << endl;
  } else
    cout << "NO" << endl;
  return 0;
}
