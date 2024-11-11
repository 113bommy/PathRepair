#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e6 + 10;
int a[MAX_N];
int b[MAX_N];
int res;
const int BUFSIZE = MAX_N;
char buf[BUFSIZE + 1];
string nextString() {
  scanf("%s", buf);
  return buf;
}
int main() {
  int n;
  cin >> n;
  map<int, int> m;
  size_t mx = 0;
  size_t cnt = 0;
  for (int i = 0; i < (n); ++i) {
    char c;
    int d;
    cin >> c >> d;
    if (c == '+') {
      m[d]++;
    } else {
      m[d]--;
      if (m[d] == 0) {
        m.erase(d);
      } else if (m[d] < 0) {
        mx++;
        m.erase(d);
      }
    }
    mx = max(mx, m.size());
  }
  cout << mx + cnt << endl;
  return 0;
}
