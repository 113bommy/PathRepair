#include <bits/stdc++.h>
using namespace std;
struct st {
  int vc;
  char lv;
  string w;
};
bool cmp(st &a, st &b) {
  if (a.vc != b.vc) return a.vc < b.vc;
  return a.lv < b.lv;
}
int main(void) {
  int n;
  int cnt;
  string inp;
  vector<st> v;
  cin >> n;
  char lv;
  for (int i = 0; i < n; i++) {
    cnt = 0;
    cin >> inp;
    for (int j = 0; j < inp.size(); j++) {
      if (inp[j] == 'a' || inp[j] == 'e' || inp[j] == 'i' || inp[j] == 'o' ||
          inp[j] == 'u') {
        lv = inp[j];
        cnt++;
      }
    }
    st res({cnt, lv, inp});
    v.push_back(res);
  }
  sort(v.begin(), v.end(), cmp);
  vector<pair<string, string> > vv, vl;
  vector<st> tmp;
  for (int i = 1; i < n; i++) {
    if (v[i].vc == v[i - 1].vc && v[i].lv == v[i - 1].lv) {
      vl.push_back(make_pair(v[i].w, v[i - 1].w));
      i++;
      if ((int)v.size() == i + 1) tmp.push_back(v[i]);
    } else {
      tmp.push_back(v[i - 1]);
      if ((int)v.size() == i + 1) tmp.push_back(v[i]);
    }
  }
  for (int i = 1; i < tmp.size(); i++) {
    if (tmp[i].vc == tmp[i - 1].vc) {
      vv.push_back(make_pair(tmp[i].w, tmp[i - 1].w));
      i++;
    }
  }
  if (vl.size() <= vv.size()) {
    cout << vl.size() << endl;
    for (int i = 0; i < vl.size(); i++)
      cout << vv[i].first << " " << vl[i].first << endl
           << vv[i].second << " " << vl[i].second << endl;
  } else {
    cout << vv.size() + (vl.size() - vv.size()) / 2 << endl;
    for (int i = 0; i < vv.size(); i++)
      cout << vv[i].first << " " << vl[i].first << endl
           << vv[i].second << " " << vl[i].second << endl;
    for (int i = vv.size(); i + 1 < vl.size(); i += 2)
      cout << vl[i + 1].first << " " << vl[i].first << endl
           << vl[i + 1].second << " " << vl[i].second << endl;
  }
}
