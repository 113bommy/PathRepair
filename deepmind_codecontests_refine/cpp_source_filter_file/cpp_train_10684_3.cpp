#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;
struct vidg {
  string name;
  int type;
  int id;
  long long widht, height;
  long long border, spacing;
  vector<int> own;
  void pack(string x);
  void set_border(long long x);
  void set_spacing(long long x);
  long long width();
  long long heigth();
};
vector<vidg> a;
map<string, int> m;
int H[1000], W[1000];
vector<pair<string, pair<long long, long long> > > res;
long long vidg::width() {
  if (this->type == 0) return this->widht;
  if (W[this->id] != -1) return W[this->id];
  if (this->own.size() == 0) return 0;
  long long res = 0;
  if (this->type == 2) {
    for (int i = 0; i < this->own.size(); i++) {
      res += a[this->own[i]].width();
    }
    res += this->spacing * (this->own.size() - 1);
    res += 2 * this->border;
    return W[this->id] = res;
  }
  for (int i = 0; i < this->own.size(); i++) {
    res = max(res, a[this->own[i]].width());
  }
  res += 2 * this->border;
  return W[this->id] = res;
}
long long vidg::heigth() {
  if (this->type == 0) return this->height;
  if (H[this->id] != -1) return H[this->id];
  if (this->own.size() == 0) return 0;
  long long res = 0;
  if (this->type == 1) {
    for (int i = 0; i < this->own.size(); i++) {
      res += a[this->own[i]].heigth();
    }
    res += this->spacing * (this->own.size() - 1);
    res += 2 * this->border;
    return H[this->id] = res;
  }
  for (int i = 0; i < this->own.size(); i++) {
    res = max(res, a[this->own[i]].heigth());
  }
  res += 2 * this->border;
  return H[this->id] = res;
}
void vidg::pack(string x) {
  int X = m[x];
  this->own.push_back(X);
}
void vidg::set_border(long long x) { this->border = x; }
void vidg::set_spacing(long long x) { this->spacing = x; }
void make_new_vidg() {
  string s;
  cin >> s;
  string name = "";
  ;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '(') break;
    name += s[i];
    s.erase(s.begin());
    i--;
  }
  s.erase(s.begin());
  long long w = 0, h = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == ',') break;
    w *= 10;
    w += s[i] - '0';
    s.erase(s.begin());
    i--;
  }
  s.erase(s.begin());
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == ')') break;
    h *= 10;
    h += s[i] - '0';
    s.erase(s.begin());
    i--;
  }
  vidg v;
  v.name = name;
  v.type = 0;
  v.height = h;
  v.widht = w;
  v.id = a.size();
  a.push_back(v);
  m[name] = a.size() - 1;
}
void make_new_vbox() {
  string name;
  cin >> name;
  vidg v;
  v.name = name;
  v.type = 1;
  v.border = 0;
  v.spacing = 0;
  v.own.clear();
  v.id = a.size();
  a.push_back(v);
  m[name] = a.size() - 1;
}
void make_new_hbox() {
  string name;
  cin >> name;
  vidg v;
  v.name = name;
  v.type = 2;
  v.border = 0;
  v.spacing = 0;
  v.own.clear();
  v.id = a.size();
  a.push_back(v);
  m[name] = a.size() - 1;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (s == "Widget") {
      make_new_vidg();
      continue;
    }
    if (s == "VBox") {
      make_new_vbox();
      continue;
    }
    if (s == "HBox") {
      make_new_hbox();
      continue;
    }
    if (s.find("pack") != string::npos) {
      string s1 = "", s2 = "";
      for (int i = 0; i < s.length(); i++) {
        if (s[i] == '.') break;
        s1 += s[i];
        s.erase(s.begin());
        i--;
      }
      s.erase(s.begin());
      s.erase(s.begin());
      s.erase(s.begin());
      s.erase(s.begin());
      s.erase(s.begin());
      s.erase(s.begin());
      for (int i = 0; i < s.length(); i++) {
        if (s[i] == ')') break;
        s2 += s[i];
        s.erase(s.begin());
        i--;
      }
      int X1 = m[s1];
      a[X1].pack(s2);
    }
    if (s.find("set_border") != string::npos) {
      string s1 = "";
      int x2 = 0;
      for (int i = 0; i < s.length(); i++) {
        if (s[i] == '.') break;
        s1 += s[i];
        s.erase(s.begin());
        i--;
      }
      s.erase(s.begin());
      s.erase(s.begin());
      s.erase(s.begin());
      s.erase(s.begin());
      s.erase(s.begin());
      s.erase(s.begin());
      s.erase(s.begin());
      s.erase(s.begin());
      s.erase(s.begin());
      s.erase(s.begin());
      s.erase(s.begin());
      s.erase(s.begin());
      for (int i = 0; i < s.length(); i++) {
        if (s[i] == ')') break;
        x2 *= 10;
        x2 += s[i] - '0';
        s.erase(s.begin());
        i--;
      }
      int X1 = m[s1];
      a[X1].set_border(x2);
    }
    if (s.find("set_spacing") != string::npos) {
      string s1 = "";
      int x2 = 0;
      for (int i = 0; i < s.length(); i++) {
        if (s[i] == '.') break;
        s1 += s[i];
        s.erase(s.begin());
        i--;
      }
      s.erase(s.begin());
      s.erase(s.begin());
      s.erase(s.begin());
      s.erase(s.begin());
      s.erase(s.begin());
      s.erase(s.begin());
      s.erase(s.begin());
      s.erase(s.begin());
      s.erase(s.begin());
      s.erase(s.begin());
      s.erase(s.begin());
      s.erase(s.begin());
      s.erase(s.begin());
      for (int i = 0; i < s.length(); i++) {
        if (s[i] == ')') break;
        x2 *= 10;
        x2 += s[i] - '0';
        s.erase(s.begin());
        i--;
      }
      int X1 = m[s1];
      a[X1].set_spacing(x2);
    }
  }
  for (int i = 0; i < a.size(); i++) {
    W[i] = H[i] = -1;
  }
  res.clear();
  for (int i = 0; i < a.size(); i++) {
    res.push_back(make_pair(a[i].name, make_pair(a[i].width(), a[i].heigth())));
  }
  sort(res.begin(), res.end());
  for (int i = 0; i < res.size(); i++) {
    cout << res[i].first << ' ' << res[i].second.first << ' '
         << res[i].second.second << endl;
  }
}
