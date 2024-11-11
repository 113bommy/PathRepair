#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
int n;
map<string, int> g;
vector<int> d;
void solution() {
  cin >> n;
  for (int i = 0, _n = (n); i < _n; ++i) {
    string s;
    int v;
    cin >> s >> v;
    g[s] = max(g[s], v);
  }
  for (map<string, int>::iterator it = g.begin(); it != g.end(); ++it)
    d.push_back(it->second);
  sort((d).begin(), (d).end());
  int m = (int)((g).size());
  cout << m << endl;
  for (map<string, int>::iterator it = g.begin(); it != g.end(); ++it) {
    cout << it->first << " ";
    int score = it->second;
    int a = 0;
    int b = 0;
    for (int j = 0, _n = ((int)((d).size())); j < _n; ++j) {
      if (d[j] <= score)
        a++;
      else
        b++;
    }
    if (b * 100 > 50 * m)
      cout << "noob" << endl;
    else if (a * 100 >= 50 * m && b * 100 > 20 * m)
      cout << "random" << endl;
    else if (a * 100 >= 80 * m && b * 100 > 10 * m)
      cout << "average" << endl;
    else if (a * 100 >= 90 * m && b * 100 > 1 * m)
      cout << "hardcore" << endl;
    else
      cout << "pro" << endl;
  }
}
int main() {
  solution();
  return 0;
}
