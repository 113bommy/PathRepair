#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
const int MAXL = 20;
int n;
map<string, int> sum;
string name[MAXN + 10];
int score[MAXN + 10];
int cnt[MAXN + 10];
int m;
int main() {
  while (cin >> n) {
    sum.clear();
    for (int i = 1; i <= n; i++) {
      string name;
      int score;
      cin >> name >> score;
      sum[name] = max(sum[name], score);
    }
    m = 0;
    for (map<string, int>::iterator it = sum.begin(); it != sum.end(); it++) {
      ++m;
      name[m] = it->first;
      score[m] = it->second;
    }
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= m; j++)
        if (score[i] < score[j]) cnt[i]++;
    cout << m << endl;
    for (int i = 1; i <= m; i++) {
      cout << name[i] << ' ';
      double rate = 1.0 * cnt[i] / m;
      if (rate > 0.5)
        puts("noob");
      else if (rate > 0.2)
        puts("random");
      else if (rate > 0.1)
        puts("average");
      else if (rate > 0.01)
        puts("hardcore");
      else
        puts("pro");
    }
  }
  return 0;
}
