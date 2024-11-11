#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
template <class T>
double sqrt(T x) {
  return sqrt((double)x);
}
template <class T>
T sqr(T x) {
  return x * x;
}
const double PI = acos(-1.0);
const int INF = 1000000000;
const int MOD = 1000000007;
int main() {
  double TIME_START = clock();
  int n, k, b, c;
  cin >> n >> k;
  vector<int> pr(n);
  vector<pair<int, int> > t, o;
  for (int x = 0; x < n; x++) {
    cin >> b >> c;
    pr[x] = b;
    if (c == 1)
      t.push_back(make_pair(b, x));
    else
      o.push_back(make_pair(b, x));
  }
  vector<vector<pair<int, int> > > kor(k);
  if (n == k) {
    int j = 0;
    for (int x = 0; x < t.size(); x++)
      kor[j++].push_back(make_pair(t[x].second, 1));
    for (int x = 0; x < o.size(); x++)
      kor[j++].push_back(make_pair(o[x].second, 2));
  } else {
    sort(t.begin(), t.end());
    reverse(t.begin(), t.end());
    sort(o.begin(), o.end());
    reverse(o.begin(), o.end());
    if (t.size() < k) {
      int j = 0;
      for (int x = 0; x < t.size(); x++)
        kor[j++].push_back(make_pair(t[x].second, 1));
      int x;
      for (x = 0; x < k - t.size() - 1; x++)
        kor[j++].push_back(make_pair(o[x].second, 2));
      for (; x < o.size(); x++) kor[j].push_back(make_pair(o[x].second, 2));
    } else {
      if (t.size() == k) {
        int j = 0;
        for (int x = 0; x < t.size(); x++)
          kor[j++].push_back(make_pair(t[x].second, 1));
        j--;
        for (int x = 0; x < o.size(); x++)
          kor[j].push_back(make_pair(o[x].second, 2));
      } else {
        int j = 0;
        int x;
        for (x = 0; x < k; x++) kor[j++].push_back(make_pair(t[x].second, 1));
        j--;
        for (; x < t.size(); x++) kor[j].push_back(make_pair(t[x].second, 1));
        for (int x = 0; x < o.size(); x++)
          kor[j].push_back(make_pair(o[x].second, 2));
      }
    }
  }
  float price = 0;
  for (int x = 0; x < kor.size(); x++) {
    float all = 0;
    bool tab = 0;
    int mi = INF;
    for (int y = 0; y < kor[x].size(); y++) {
      all += pr[kor[x][y].first];
      mi = min(mi, pr[kor[x][y].first]);
      if (kor[x][y].second == 1) tab = 1;
    }
    if (tab == 0)
      price += all;
    else
      price += all - mi / 2.;
  }
  char s[50];
  sprintf(s, "%.2f", price);
  s[strlen(s) - 1] = 0;
  cout << s << endl;
  for (int x = 0; x < k; x++) {
    cout << kor[x].size();
    for (int y = 0; y < kor[x].size(); y++) cout << " " << kor[x][y].first + 1;
    cout << endl;
  }
  fprintf(stderr, "\n\n%.15lf\n\n",
          (double)(clock() - TIME_START) / CLOCKS_PER_SEC);
  return 0;
}
