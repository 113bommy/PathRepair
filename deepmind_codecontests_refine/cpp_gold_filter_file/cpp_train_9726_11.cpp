#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;
struct node {
  bool isfirstwin;
  int firstcount;
  int secondcount;
};
map<string, node> M;
int n;
vector<string> V;
bool Check(string str) {
  if (str == "") return true;
  for (int i = 0; i < V.size(); i++)
    if (V[i].find(str) != V[i].npos) return true;
  return false;
}
int CalcCount(string s) {
  int res = 0;
  int maxval = -1;
  for (int i = 0; i < s.size(); i++)
    res += s[i] - 'a' + 1, maxval = max(maxval, s[i] - 'a' + 1);
  res *= maxval;
  int k = 0;
  for (int i = 0; i < V.size(); i++)
    if (V[i].find(s) != V[i].npos) k++;
  res += k;
  return res;
}
bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.first != b.first) return a.first < b.first;
  return a.second > b.second;
}
pair<int, int> getmax(pair<int, int> a, pair<int, int> b) {
  if (cmp(a, b))
    return b;
  else
    return a;
}
void Calc(string str) {
  if (M.find(str) != M.end()) return;
  M[str] = node();
  string newstr;
  bool f = false;
  bool waslose = false;
  pair<int, int> bestwin(-inf, inf);
  pair<int, int> bestlose(-inf, inf);
  for (char c = 'a'; c <= 'z'; c++) {
    newstr = str;
    newstr.push_back(c);
    if (Check(newstr)) {
      Calc(newstr);
      pair<int, int> p;
      p.first = M[newstr].secondcount + CalcCount(newstr);
      p.second = M[newstr].firstcount;
      f = true;
      waslose = (waslose || !M[newstr].isfirstwin);
      if (!M[newstr].isfirstwin)
        bestwin = getmax(bestwin, p);
      else
        bestlose = getmax(bestlose, p);
    }
  }
  for (char c = 'a'; c <= 'z'; c++) {
    newstr.clear();
    newstr.push_back(c);
    newstr = newstr + str;
    if (Check(newstr)) {
      Calc(newstr);
      pair<int, int> p;
      p.first = M[newstr].secondcount + CalcCount(newstr);
      p.second = M[newstr].firstcount;
      f = true;
      waslose = (waslose || !M[newstr].isfirstwin);
      if (!M[newstr].isfirstwin)
        bestwin = getmax(bestwin, p);
      else
        bestlose = getmax(bestlose, p);
    }
  }
  if (!f) {
    M[str].isfirstwin = false;
    M[str].firstcount = M[str].secondcount = 0;
    return;
  }
  if (waslose) {
    M[str].isfirstwin = true;
    M[str].firstcount = bestwin.first;
    M[str].secondcount = bestwin.second;
  } else {
    M[str].isfirstwin = false;
    M[str].firstcount = bestlose.first;
    M[str].secondcount = bestlose.second;
  }
}
int main() {
  cin >> n;
  V.resize(n);
  for (int i = 0; i < n; i++) cin >> V[i];
  Calc("");
  if (M[""].isfirstwin)
    cout << "First" << endl;
  else
    cout << "Second" << endl;
  cout << M[""].firstcount << ' ' << M[""].secondcount;
}
