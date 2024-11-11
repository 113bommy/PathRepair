#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e5 + 1;
map<string, int> u;
vector<string> q;
string s, t;
int n;
bool cmp(string a, string b) {
  if (u[a] == u[b]) {
    return a < b;
  }
  return u[a] > u[b];
}
int main() {
  cin >> s >> n;
  for (int i = 1; i <= n; i++) {
    getline(cin, t);
    int k = 0;
    string w = "", e = "";
    for (int j = 0; j < t.size(); j++) {
      if (t[j] == ' ') {
        if (t[j + 1] == 'p') {
          k = 1;
        }
        if (t[j + 1] == 'c') {
          k = 2;
        }
        if (t[j + 1] == 'l') {
          k = 3;
        }
        break;
      }
      w += t[j];
    }
    int r = 0;
    if (k == 1) {
      for (int j = 0; j < t.size(); j++) {
        if (r == 3) {
          e += t[j];
        }
        if (t[j] == ' ') {
          r++;
        }
        if (r == 4) {
          e.pop_back();
          e.pop_back();
          e.pop_back();
          break;
        }
      }
      if (w == s) {
        u[e] += 15;
      }
      if (e == s) {
        u[w] += 15;
      }
    } else if (k == 2) {
      for (int j = 0; j < t.size(); j++) {
        if (r == 3) {
          e += t[j];
        }
        if (t[j] == ' ') {
          r++;
        }
        if (r == 4) {
          e.pop_back();
          e.pop_back();
          e.pop_back();
          break;
        }
      }
      if (w == s) {
        u[e] += 10;
      }
      if (e == s) {
        u[w] += 10;
      }
    } else {
      for (int j = 0; j < t.size(); j++) {
        if (r == 2) {
          e += t[j];
        }
        if (t[j] == ' ') {
          r++;
        }
        if (r == 3) {
          e.pop_back();
          e.pop_back();
          e.pop_back();
          break;
        }
      }
      if (w == s) {
        u[e] += 5;
      }
      if (e == s) {
        u[w] += 5;
      }
    }
    q.push_back(w);
    q.push_back(e);
  }
  sort(q.begin(), q.end());
  q.resize(unique(q.begin(), q.end()) - q.begin());
  sort(q.begin(), q.end(), &cmp);
  for (string i : q) {
    if (i == s) continue;
    cout << i << "\n";
  }
}
