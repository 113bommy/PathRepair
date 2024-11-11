#include <bits/stdc++.h>
using namespace std;
vector<string> split(const string& s, const string& delim = " ") {
  vector<string> res;
  string t;
  for (int i = 0; i != s.size(); i++) {
    if (delim.find(s[i]) != string::npos) {
      if (!t.empty()) {
        res.push_back(t);
        t = "";
      }
    } else {
      t += s[i];
    }
  }
  if (!t.empty()) {
    res.push_back(t);
  }
  return res;
}
vector<int> splitInt(const string& s, const string& delim = " ") {
  vector<string> tok = split(s, delim);
  vector<int> res;
  for (int i = 0; i != tok.size(); i++) res.push_back(atoi(tok[i].c_str()));
  return res;
}
template <typename T>
void print(T a) {
  cerr << a;
}
static void print(long long a) { cerr << a << "L"; }
static void print(string a) { cerr << '"' << a << '"'; }
template <typename T>
void print(vector<T> a) {
  cerr << "{";
  for (int i = 0; i != a.size(); i++) {
    if (i != 0) cerr << ", ";
    print(a[i]);
  }
  cerr << "}" << endl;
}
int main() {
  int n, m, a;
  while (cin >> n >> m) {
    priority_queue<pair<int, int> > pq;
    for (int i = 0, _n = (n); i < _n; i++) {
      scanf("%d", &a);
      if (a == 0) continue;
      pq.push(make_pair(a, i + 1));
    }
    bool can = true;
    queue<pair<int, int> > q;
    vector<pair<int, int> > res;
    while (!pq.empty() && can) {
      pair<int, int> t = pq.top();
      pq.pop();
      if (t.first == 0) continue;
      for (int i = 0, _n = (t.first); i < _n; i++) {
        if (pq.empty()) {
          can = false;
          break;
        }
        pair<int, int> temp = pq.top();
        pq.pop();
        res.push_back(make_pair(t.second, temp.second));
        temp.first--;
        if (temp.first) q.push(temp);
      }
      while (!q.empty()) pq.push(q.front()), q.pop();
    }
    if (!can)
      puts("NO");
    else {
      puts("YES");
      printf("%d\n", res.size());
      for (int i = 0, _n = (res.size()); i < _n; i++)
        printf("%d %d\n", res[i].first, res[i].second);
    }
  }
  return 0;
}
