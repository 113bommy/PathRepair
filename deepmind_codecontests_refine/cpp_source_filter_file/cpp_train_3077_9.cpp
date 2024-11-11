#include <bits/stdc++.h>
using namespace std;
template <class T>
void pv(T a, T b) {
  for (T i = a; i != b; ++i) cerr << *i << ' ';
  cout << endl;
}
int main() {
  for (int n; cin >> n >> ws;) {
    string line;
    getline(cin, line);
    vector<int> end;
    for (int i = 0; i < line.size(); i++) {
      if (line[i] == '.' || line[i] == '?' || line[i] == '!') end.push_back(i);
    }
    vector<int> beg;
    beg.push_back(0);
    for (int i = 0; i + 1 < end.size(); i++) {
      int p = end[i];
      while (isdigit(line[++p]))
        ;
      beg.push_back(p);
    }
    int N = beg.size();
    int ans = 0;
    int start = 0;
    for (int i = 0; i < N; i++) {
      if (end[i] - beg[i] + 1 > n) {
        ans = -1;
        break;
      }
      if (end[i] - start + 1 > n) {
        ans++;
        start = beg[i];
      }
    }
    if (ans == -1)
      cout << "Impossible" << endl;
    else {
      cout << ans << endl;
    }
  }
  return 0;
}
