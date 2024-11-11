#include <bits/stdc++.h>
using namespace std;
bool IsHappy(int n) {
  while (n > 0) {
    if ((n % 10 == 4) || (n % 10 == 7)) {
      n /= 10;
    } else {
      return false;
    }
  }
  return true;
}
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  bool happy = false;
  int index_happy;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (IsHappy(a[i])) {
      happy = true;
      index_happy = i;
    }
  }
  if (!happy) {
    for (int i = 1; i < n; ++i) {
      if (a[i] < a[i - 1]) {
        cout << -1;
        return 0;
      }
    }
    cout << 0;
    return 0;
  }
  vector<pair<int, int> > b(n);
  for (int i = 0; i < n; ++i) {
    b[i] = make_pair(a[i], i);
  }
  sort(b.begin(), b.end());
  vector<int> position(n);
  vector<int> who(n);
  for (int i = 0; i < n; ++i) {
    position[i] = who[i] = i;
  }
  vector<pair<int, int> > answer;
  int k = index_happy;
  int o;
  for (int i = 0; i < n; ++i) {
    if (b[i].second == index_happy) {
      o = i;
      break;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (i != o) {
      if (b[i].second != who[i]) {
        if (k != i) {
          answer.push_back(make_pair(k, i));
        }
        if (i != position[b[i].second]) {
          answer.push_back(make_pair(i, position[b[i].second]));
        }
        who[k] = who[i];
        position[who[i]] = k;
        int t = position[b[i].second];
        position[b[i].second] = i;
        who[i] = b[i].second;
        who[t] = index_happy;
        position[index_happy] = t;
        k = t;
      }
    }
  }
  cout << answer.size() << "\n";
  for (int i = 0; i < answer.size(); ++i) {
    if (answer[i].first != answer[i].second) {
      cout << answer[i].first + 1 << " " << answer[i].second + 1 << "\n";
    }
  }
  return 0;
}
