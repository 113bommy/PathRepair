#include <bits/stdc++.h>
using namespace std;
int t;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  for (int i = 0; i < t; i++) {
    long double min1 = -1;
    int n;
    cin >> n;
    vector<long long> v;
    vector<pair<long long, long long> > v2;
    int side1 = 0, side2 = 0;
    for (int j = 0; j < n; j++) {
      int a;
      cin >> a;
      v.push_back(a);
    }
    sort(v.begin(), v.end());
    for (int j = 0; j < n; j++) {
      int cnt = 1;
      while (j < n - 1 && v[j] == v[j + 1]) {
        j++;
        cnt++;
      }
      v2.push_back(make_pair(v[j], cnt));
    }
    int b = -1;
    for (int j = 0; j < v2.size(); j++) {
      if (v2[j].second < 2) continue;
      if (j != 0 && b != -1) {
        if (min1 < 0 ||
            (long double)((long double)2 * (v2[j].first + v2[b].first)) *
                    ((long double)2 * (v2[j].first + v2[b].first)) /
                    ((long double)v2[j].first * v2[b].first) <
                min1) {
          min1 = (long double)((long double)2 * (v2[j].first + v2[b].first)) *
                 ((long double)2 * (v2[j].first + v2[b].first)) /
                 ((long double)v2[j].first * v2[b].first);
          side1 = v2[j].first;
          side2 = v2[b].first;
        }
      }
      b = j;
      if (v2[j].second >= 4)
        if (min1 < 0 || (long double)(2 * (v2[j].first + v2[j].first)) *
                                (2 * (v2[j].first + v2[j].first)) /
                                (v2[j].first * v2[j].first) <
                            min1) {
          min1 = (long double)((long double)2 * (v2[j].first + v2[j].first)) *
                 ((long double)2 * (v2[j].first + v2[j].first)) /
                 ((long double)v2[j].first * v2[j].first);
          side1 = v2[j].first;
          side2 = v2[j].first;
        }
    }
    if (side1 == 0) exit(-1);
    cout << side1 << ' ' << side1 << ' ' << side2 << ' ' << side2 << endl;
  }
}
