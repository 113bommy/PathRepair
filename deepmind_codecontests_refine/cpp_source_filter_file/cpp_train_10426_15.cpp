#include <bits/stdc++.h>
using namespace std;
const int OO = (int)2e9;
const double PI = 2 * acos(0.0);
const double EPS = 1e-9;
int dcmp(double a, double b) { return fabs(a - b) <= EPS ? 0 : a > b ? 1 : 2; }
int DI[] = {-1, 0, 1, 0, 1, -1, -1, 1};
int DJ[] = {0, 1, 0, -1, 1, -1, 1, -1};
string male[] = {"lios", "etr", "initis"};
string female[] = {"liala", "etra", "inites"};
vector<string> zbt(string str) {
  vector<string> ret;
  string tmp = "";
  for (int i = 0; i < (int)str.size(); i++) {
    if (str[i] == ' ') {
      ret.push_back(tmp);
      tmp = "";
    } else
      tmp += str[i];
  }
  if ((int)tmp.size()) ret.push_back(tmp);
  return ret;
}
bool checkMale(vector<string> words) {
  for (int i = 0; i < (int)words.size(); i++) {
    bool ok = 0;
    for (int j = 0; j < 3; j++) {
      int idx = words[i].find(male[j]);
      if (idx != -1 && idx + (int)male[j].size() == (int)words[i].size()) {
        ok = 1;
        break;
      }
    }
    if (!ok) return 0;
  }
  return 1;
}
bool checkFemale(vector<string> words) {
  for (int i = 0; i < (int)words.size(); i++) {
    bool ok = 0;
    for (int j = 0; j < 3; j++) {
      int idx = words[i].find(female[j]);
      if (idx != -1 && idx + (int)female[j].size() == (int)words[i].size()) {
        ok = 1;
        break;
      }
    }
    if (!ok) return 0;
  }
  return 1;
}
bool noun(string str) {
  int idx = str.find("etr");
  int idx2 = str.find("etra");
  if (idx != -1 && idx + 3 == (int)str.size()) return 1;
  if (idx2 != -1 && idx2 + 4 == (int)str.size()) return 1;
  return 0;
}
bool adj(string str) {
  int idx = str.find("lios");
  int idx2 = str.find("liala");
  if (idx != -1 && idx + 4 == (int)str.size()) return 1;
  if (idx2 != -1 && idx2 + 5 == (int)str.size()) return 1;
  return 0;
}
bool verb(string str) {
  int idx = str.find("initis");
  int idx2 = str.find("inites");
  if (idx != -1 && idx + 6 == (int)str.size()) return 1;
  if (idx2 != -1 && idx2 + 6 == (int)str.size()) return 1;
  return 0;
}
bool ok(vector<string> words) {
  if ((int)words.size() == 1) return 1;
  int idx = -1;
  for (int i = 0; i < (int)words.size(); i++)
    if (noun(words[i])) {
      idx = i;
      break;
    }
  if (idx == -1) return 0;
  for (int i = 0; i < idx; i++)
    if (!adj(words[i])) return 0;
  for (int i = idx + 1; i < (int)words.size(); i++)
    if (!verb(words[i])) return 0;
  return 1;
}
int main() {
  string str;
  getline(cin, str);
  vector<string> words = zbt(str);
  int ans = checkMale(words) + checkFemale(words);
  if (ans == 0 || ans > 1 || !ok(words))
    cout << "NO\n";
  else
    cout << "YES\n";
  return 0;
}
