#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  string t;
  cin >> t;
  int f = 0;
  for (int i = 0; i < t.length(); i++) {
    if (t[i] == 'S') {
      f++;
    }
  }
  if (f == 1) {
    cout << t.length() - 1 << endl;
    return 0;
  }
  if (f == 0) {
    cout << t.length() << endl;
    return 0;
  }
  if (f == t.length()) {
    cout << "0" << endl;
    return 0;
  }
  vector<pair<int, int> > arr;
  int start = -1;
  int end = -1;
  for (int i = 0; i < t.length(); i++) {
    if (t[i] == 'G' && start == -1) {
      start = i;
      end = i;
    } else if (t[i] == 'G' && start < i) {
      end = i;
    } else if (t[i] == 'S') {
      if (start != -1) {
        arr.push_back(make_pair(start, end));
      }
      start = -1;
      end = -1;
    }
  }
  if (t[t.length() - 1] == 'G') {
    arr.push_back(make_pair(start, end));
  }
  int ans = -1;
  if (f) {
    for (int i = 0; i < arr.size() - 1; i++) {
      if (arr[i + 1].first - arr[i].second == 2 && arr.size() > 2) {
        int length = arr[i + 1].second - arr[i].first + 1;
        ans = max(length, ans);
      } else if (arr[i + 1].first - arr[i].second == 2 && arr.size() == 2) {
        int length = arr[i + 1].second - arr[i].first;
        ans = max(length, ans);
      }
    }
    for (int i = 0; i < arr.size(); i++) {
      if (arr.size() > 2) {
        ans = max(ans, arr[i].second + 1 - arr[i].first + 1);
      } else {
        ans = max(ans, arr[i].second + 1 - arr[i].first);
      }
    }
  } else {
    for (int i = 0; i < arr.size(); i++) {
      ans = max(ans, arr[i].second - arr[i].first + 1);
    }
  }
  cout << ans << endl;
  return 0;
}
