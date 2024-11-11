#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > v;
int n, a, b;
vector<int> first, second;
bool solve(int a, int b) {
  long long sum = INT_MAX;
  int cnt = 0;
  int flag = 0, flag2 = 0;
  for (int i = 0; i < n; i++) {
    sum = min(sum, (long long)v[i].first);
    cnt++;
    if (sum * cnt >= (long long)a) {
      flag2 = 1;
      sum = INT_MAX;
      cnt = 0;
      for (int j = i + 1; j < n; j++) {
        sum = min(sum, (long long)v[j].first);
        cnt++;
        if (sum * cnt >= (long long)b) {
          for (int k = 0; k <= i; k++) {
            first.push_back(v[k].second);
          }
          for (int k = i + 1; k <= j; k++) {
            second.push_back(v[k].second);
          }
          flag = 1;
          break;
        }
      }
      if (flag2) {
        break;
      }
    }
  }
  if (flag && flag2) {
    return true;
  }
  return false;
}
int main() {
  cin >> n >> a >> b;
  v.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first;
    v[i].second = i;
  }
  sort(v.rbegin(), v.rend());
  first.clear();
  second.clear();
  if (solve(a, b)) {
    cout << "YES" << endl;
    cout << first.size() << " " << second.size() << endl;
    for (int i = 0; i < first.size(); i++) {
      cout << first[i] + 1 << " ";
    }
    cout << endl;
    for (int i = 0; i < second.size(); i++) {
      cout << second[i] + 1 << " ";
    }
    cout << endl;
  } else if (solve(b, a)) {
    cout << "YES" << endl;
    cout << second.size() << " " << first.size() << endl;
    for (int i = 0; i < second.size(); i++) {
      cout << second[i] + 1 << " ";
    }
    cout << endl;
    for (int i = 0; i < first.size(); i++) {
      cout << first[i] + 1 << " ";
    }
    cout << endl;
  } else {
    cout << "NO" << endl;
  }
}
