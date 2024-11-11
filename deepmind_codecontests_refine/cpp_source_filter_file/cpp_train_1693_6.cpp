#include <bits/stdc++.h>
const int maxn = 1e6 + 10;
using namespace std;
char b[maxn];
char a[maxn];
deque<int> q;
int main() {
  int T;
  cin >> T;
  while (T--) {
    while (q.size()) {
      q.pop_back();
    }
    int n;
    cin >> n;
    scanf("%s", a);
    scanf("%s", b);
    for (int i = 0; i < n; i++) {
      a[i] -= '0';
      b[i] -= '0';
      q.push_back(b[i]);
    }
    bool nowtail = true;
    int reversecnt = 0;
    int changcnt = 0;
    int aarr = n - 1;
    vector<int> saveans;
    while (aarr >= 0) {
      int nowval = a[aarr];
      if (a[aarr] == q.back()) {
        q.pop_back();
      } else {
        if (q.front() == nowval) {
          saveans.push_back(1);
        }
        saveans.push_back(q.size());
        q.pop_front();
        saveans.push_back(q.size());
      }
      aarr--;
    }
    int cnt = 0;
    for (int aa : saveans) {
      if (aa != 0) cnt++;
    }
    cout << cnt;
    for (int aa : saveans) {
      if (aa != 0) {
        printf(" %d", aa);
      }
    }
    printf("\n");
  }
}
