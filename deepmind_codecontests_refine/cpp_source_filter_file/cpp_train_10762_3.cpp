#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t, t1, time = 0, size = 0, s;
  vector<pair<int, int> > V;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &t, &t1);
    V.push_back(make_pair(t, t1));
  }
  sort(V.begin(), V.end());
  time = V[0].first + V[0].second;
  size = V[0].second;
  s = 0;
  for (int i = 1; i < n; i++) {
    if (time > V[i].first) {
      size = size - (V[i].first - V[i - 1].first) + V[i].second;
      time += V[i].second;
    } else {
      time = V[i].first + V[i].second;
      size = V[i].second;
    }
    s = max(s, size);
  }
  cout << time << " " << s << endl;
}
