#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n, instruments;
  cin >> n;
  cin >> instruments;
  vector<pair<int, int> > time(n);
  for (int i = 0; i < n; i++) {
    cin >> time[i].second;
    time[i].first = i;
  }
  sort(time.begin(), time.end(), comp);
  int rqdtime = 0;
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (rqdtime + time[i].second <= instruments) {
      count++;
      rqdtime += time[i].second;
    } else {
      break;
    }
  }
  cout << count << endl;
  for (int i = 0; i < count; i++) {
    cout << time[i].first + 1 << " ";
  }
  return 0;
}
