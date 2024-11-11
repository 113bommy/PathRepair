#include <bits/stdc++.h>
using namespace std;
int t;
char buf[100002];
int n;
vector<pair<int, int> > v;
bool adj[100002];
char ress[100002];
string res;
void outt() {
  if (v.size() == 0) return;
  cout << "Q " << v.size();
  for (int i = 0; i < v.size(); i++) {
    printf(" ");
    printf("%d %d", v[i].first + 1, v[i].second + 1);
  }
  puts("");
  fflush(stdout);
  scanf("%s", ress);
  res = ress;
}
vector<pair<int, int> > con;
bool sm[100002];
vector<int> idx;
void ot(vector<int> &z) {
  for (int i = 0; i < z.size(); i++) {
    if (i) printf(" ");
    printf("%d", z[i]);
  }
  puts("");
  fflush(stdout);
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    if (n == -1) {
      exit(1);
    }
    v.clear();
    con.clear();
    for (int i = 0; i + 1 < n; i += 2) {
      v.push_back(make_pair(i, i + 1));
    }
    outt();
    int p = 0;
    for (int i = 0; i < res.size(); i++) {
      adj[p] = res[i] - '0';
      p += 2;
    }
    v.clear();
    for (int i = 1; i < n; i += 2) {
      v.push_back(make_pair(i, i + 1));
    }
    outt();
    p = 1;
    for (int i = 0; i < res.size(); i++) {
      adj[p] = res[i] - '0';
      p += 2;
    }
    adj[n - 1] = 0;
    int lef = 0;
    for (int i = 0; i < n; i++) {
      if (adj[i] == 0) {
        con.push_back(make_pair(lef, i));
        lef = i + 1;
      } else {
        continue;
      }
    }
    v.clear();
    for (int i = 0; i + 2 < con.size(); i++) {
      if (i % 4 < 2) {
        v.push_back(make_pair(con[i].first, con[i + 2].first));
      }
    }
    outt();
    v.clear();
    int ps = 0;
    for (int i = 0; i + 2 < con.size(); i++) {
      if (i % 4 < 2) {
        sm[i + 2] = res[ps++] - '0';
      }
    }
    for (int i = 0; i + 2 < con.size(); i++) {
      if (i % 4 >= 2) {
        v.push_back(make_pair(con[i].first, con[i + 2].first));
      }
    }
    outt();
    ps = 0;
    for (int i = 0; i + 2 < con.size(); i++) {
      if (i % 4 >= 2) {
        sm[i + 2] = res[ps++] - '0';
      }
    }
    idx.clear();
    idx.push_back(0);
    idx.push_back(1);
    for (int i = 2; i < con.size(); i++) {
      if (sm[i] == true) {
        idx.push_back(idx[idx.size() - 2]);
        continue;
      }
      if (sm[i] == false) {
        set<int> f;
        f.insert(0);
        f.insert(1);
        f.insert(2);
        f.erase(idx.back());
        f.erase(idx[idx.size() - 2]);
        idx.push_back(*f.begin());
      }
    }
    map<int, vector<int> > mp;
    mp.clear();
    for (int i = 0; i < con.size(); i++) {
      for (int j = con[i].first; j < con[i].second + 1; j++) {
        mp[idx[i]].push_back(j + 1);
      }
    }
    cout << "A " << mp[0].size() << " " << mp[1].size() << " " << mp[2].size()
         << endl;
    ot(mp[0]);
    ot(mp[1]);
    ot(mp[2]);
  }
  return 0;
}
