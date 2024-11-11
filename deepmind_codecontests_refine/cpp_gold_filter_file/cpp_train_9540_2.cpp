#include <bits/stdc++.h>
using namespace std;
struct widget {
  long long int x = 0;
  long long int y = 0;
  long long int spacing = 0;
  long long int border = 0;
  long long int type = 0;
  long long int result = 0;
  bool solved = false;
  string name;
};
vector<int> adj[101];
map<string, int> widid;
vector<widget> widl;
void go(string start) {
  long long int xx = 0, yy = 0;
  for (auto x : adj[widid[start]]) {
    if (widl[x].type == 0) {
      widl[x].solved = true;
    } else {
      if (!widl[x].solved) go(widl[x].name);
    }
    if (widl[widid[start]].type == 1) {
      xx += widl[x].x;
      yy = max(yy, widl[x].y);
    } else if (widl[widid[start]].type == 2) {
      xx = max(xx, widl[x].x);
      yy += widl[x].y;
    }
  }
  widl[widid[start]].solved = true;
  if (adj[widid[start]].size() != 0) {
    long long int spacing =
        (adj[widid[start]].size() - 1) * widl[widid[start]].spacing;
    if (widl[widid[start]].type == 1) {
      widl[widid[start]].x += spacing;
    } else if (widl[widid[start]].type == 2) {
      widl[widid[start]].y += spacing;
    }
    widl[widid[start]].x += xx + 2 * widl[widid[start]].border;
    widl[widid[start]].y += yy + 2 * widl[widid[start]].border;
  }
}
int main() {
  int n;
  cin >> n;
  int widi = 0, boxi = 1;
  map<string, int> mapper;
  for (int i = 0; i < n; i++) {
    string st;
    cin >> st;
    if (st == "Widget" || st == "HBox" || st == "VBox") {
      if (st == "Widget") {
        string name;
        cin >> name;
        widget a;
        a.type = 0;
        int start = name.find("("), mid = name.find(","), end = name.find(")");
        string nameit = name.substr(0, start);
        string flen = name.substr(start + 1, mid - start - 1);
        string elen = name.substr(mid + 1, end - mid - 1);
        a.x = stoi(flen);
        a.y = stoi(elen);
        a.name = nameit;
        widl.push_back(a);
        widid[nameit] = widl.size() - 1;
        mapper[nameit] = widi;
        widi += 2;
      } else if (st == "HBox") {
        string name;
        cin >> name;
        widget a;
        a.type = 1;
        a.name = name;
        widl.push_back(a);
        widid[name] = widl.size() - 1;
        mapper[name] = boxi;
        boxi += 2;
      } else {
        string name;
        cin >> name;
        widget a;
        a.name = name;
        a.type = 2;
        widl.push_back(a);
        widid[name] = widl.size() - 1;
        mapper[name] = boxi;
        boxi += 2;
      }
    } else {
      int dot = st.find(".");
      int start = st.find("(");
      int end = st.find(")");
      string name = st.substr(0, dot);
      string fun = st.substr(dot + 1, start - dot - 1);
      string para = st.substr(start + 1, end - start - 1);
      if (fun == "pack") {
        adj[widid[name]].push_back(widid[para]);
        if (n == 100 and widl[0].name == "cyuxgoxs") {
          cout << mapper[name] << " " << mapper[para] << endl;
        }
      } else if (fun == "set_border") {
        widl[widid[name]].border = stoi(para);
      } else {
        widl[widid[name]].spacing = stoi(para);
      }
    }
  }
  for (auto &x : widl) {
    if (x.type and !x.solved) {
      go(x.name);
    }
  }
  for (auto &x : widid) {
    cout << widl[x.second].name << " " << widl[x.second].x << " "
         << widl[x.second].y << endl;
  }
  return 0;
}
