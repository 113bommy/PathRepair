#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<pair<int, int> > laptops(N);
  for (int i = 0; i < N; i++) {
    cin >> laptops[i].first >> laptops[i].second;
  }
  sort(laptops.begin(), laptops.end());
  bool p = false;
  for (int i = 0; i < N - 1; i++) {
    if (laptops[i].first < laptops[i + 1].first &&
        laptops[i].second > laptops[i + 1].second)
      p = true;
  }
  cout << (p ? "Happy Alex" : "Poor Alex") << endl;
  return 0;
}
