#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
struct Widget {
  string name;
  int hor;
  int border;
  int spacing;
  long long first, second;
  bool calculated;
  vector<string> nxt;
  Widget() {
    border = 0;
    spacing = 0;
    first = second = 0;
    calculated = false;
  }
};
bool operator<(const Widget& w1, const Widget& w2) { return w1.name < w2.name; }
int n;
char s[1000];
vector<Widget> a;
set<string> used;
Widget& getWidget(string name) {
  for (int i = 0, _n = ((int)((a).size())); i < _n; ++i)
    if (a[i].name == name) return a[i];
  throw 1;
  return a[(int)((a).size())];
}
void calculate(Widget& w) {
  if (w.calculated || !(int)((w.nxt).size())) return;
  long long X = 0, Y = 0;
  long long mX = 0, mY = 0;
  for (int i = 0, _n = ((int)((w.nxt).size())); i < _n; ++i) {
    Widget& c = getWidget(w.nxt[i]);
    calculate(c);
    X += c.first, Y += c.second;
    mX = max(mX, c.first);
    mY = max(mY, c.second);
  }
  if (w.hor == 1) {
    w.first = X + w.border * 2 + w.spacing * ((int)((w.nxt).size()) - 1);
    w.second = mY + w.border * 2;
  } else {
    w.first = mX + w.border * 2;
    w.second = Y + w.border * 2 + w.spacing * ((int)((w.nxt).size()) - 1);
  }
  w.calculated = true;
}
void solution() {
  scanf("%d\n", &n);
  for (int it = 0, _n = (n); it < _n; ++it) {
    gets(s);
    for (int i = 0, _n = (strlen(s)); i < _n; ++i)
      if (s[i] == '(' || s[i] == ')' || s[i] == '.') s[i] = ' ';
    if (s[0] == 'W') {
      char name[11];
      int first, second;
      sscanf(s, "Widget %s %d,%d ", name, &first, &second);
      Widget w;
      w.name = string(name);
      w.hor = -1;
      w.first = first;
      w.second = second;
      a.push_back(w);
    } else if (s[0] == 'V') {
      char name[11];
      sscanf(s, "VBox %s", name);
      Widget w;
      w.name = string(name);
      w.hor = 0;
      a.push_back(w);
    } else if (s[0] == 'H') {
      char name[11];
      sscanf(s, "HBox %s", name);
      Widget w;
      w.name = string(name);
      w.hor = 1;
      a.push_back(w);
    } else {
      char name[11];
      char op[12];
      char param[11];
      int first, second;
      sscanf(s, "%s %s %s", name, op, param);
      Widget& w = getWidget(string(name));
      if (op[0] == 'p')
        w.nxt.push_back(string(param));
      else if (op[4] == 's')
        w.spacing = atoi(param);
      else
        w.border = atoi(param);
    }
  }
  for (int i = 0, _n = ((int)((a).size())); i < _n; ++i) calculate(a[i]);
  sort((a).begin(), (a).end());
  for (int i = 0, _n = ((int)((a).size())); i < _n; ++i)
    printf("%s %lld %lld\n", a[i].name.c_str(), a[i].first, a[i].second);
}
int main() {
  solution();
  return 0;
}
