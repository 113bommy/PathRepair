#include <bits/stdc++.h>
using namespace std;
const int H = 1, V = 2;
int n;
map<string, vector<string>> inside;
map<string, int> boxtype;
map<string, int> boxbord, boxspace;
map<string, pair<int, int>> widprop;
map<string, pair<long long, long long>> res;
pair<long long, long long> calc(string name) {
  if (res.find(name) != res.end()) return res[name];
  if (widprop.find(name) != widprop.end()) {
    res[name] = widprop[name];
    return res[name];
  };
  long long x = 0, y = 0;
  pair<long long, long long> temp;
  vector<string> &t = inside[name];
  for (int i = 0; i < t.size(); i++) {
    temp = calc(t[i]);
    if (boxtype[name] == V) {
      y += temp.second;
      x = max(x, temp.first);
    } else {
      x += temp.first;
      y = max(y, temp.second);
    };
  };
  if (t.size() == 0)
    res[name] = make_pair(0, 0);
  else if (boxtype[name] == V)
    res[name] = make_pair(boxbord[name] * 2 + x,
                          boxbord[name] * 2 +
                              ((t.size() - 1) * boxspace[name] > 0
                                   ? (t.size() - 1) * boxspace[name]
                                   : 0) +
                              y);
  else
    res[name] = make_pair(boxbord[name] * 2 +
                              ((t.size() - 1) * boxspace[name] > 0
                                   ? (t.size() - 1) * boxspace[name]
                                   : 0) +
                              x,
                          boxbord[name] * 2 + y);
  return res[name];
};
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int p;
    string a;
    cin >> a;
    if ((p = a.find('.')) == -1) {
      if (a == "Widget") {
        string b;
        cin >> b;
        int p1 = b.find('('), p2 = b.find(')'), p3 = b.find(',');
        string obj = b.substr(0, p1), x = b.substr(p1 + 1, p3 - p1 - 1),
               y = b.substr(p3 + 1, p2 - p3 - 1);
        widprop[obj] = make_pair(atoi(x.c_str()), atoi(y.c_str()));
      } else if (a == "HBox") {
        string b;
        cin >> b;
        boxtype[b] = H;
      } else if (a == "VBox") {
        string b;
        cin >> b;
        boxtype[b] = V;
      };
    } else {
      int p1 = a.find('('), p2 = a.find(')');
      string obj = a.substr(0, p), funca = a.substr(p + 1, p1 - p - 1),
             param = a.substr(p1 + 1, p2 - p1 - 1);
      if (funca == "pack")
        inside[obj].push_back(param);
      else if (funca == "set_border")
        boxbord[obj] = atoi(param.c_str());
      else if (funca == "set_spacing")
        boxspace[obj] = atoi(param.c_str());
    };
  };
  for (map<string, int>::iterator i = boxtype.begin(); i != boxtype.end(); i++)
    calc(i->first);
  for (map<string, pair<int, int>>::iterator i = widprop.begin();
       i != widprop.end(); i++)
    calc(i->first);
  for (map<string, pair<long long, long long>>::iterator i = res.begin();
       i != res.end(); i++)
    cout << i->first << ' ' << i->second.first << ' ' << i->second.second
         << endl;
  return 0;
}
