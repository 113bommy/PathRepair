#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, n;
  cin >> k >> n;
  set<int> point;
  int sum = 0;
  for (int i = 0; i < (int)(k); i++) {
    int p;
    cin >> p;
    sum += p;
    point.insert(sum);
  }
  vector<int> remember;
  for (int i = 0; i < (int)(n); i++) {
    int p;
    cin >> p;
    remember.push_back(p);
  }
  int cnt = 0;
  for (auto itr = point.begin(); itr != point.end(); itr++) {
    bool isPossible = true;
    for (int i = 0; i < (int)(n - 1); i++) {
      if (point.count(remember[i + 1] - (remember[0] - *itr)) > 0)
        isPossible = false;
    }
    if (isPossible) cnt++;
  }
  cout << cnt << endl;
  return 0;
}
