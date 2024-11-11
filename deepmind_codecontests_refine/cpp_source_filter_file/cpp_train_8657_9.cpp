#include <bits/stdc++.h>
using namespace std;
bool ap(vector<pair<long long, int> > &num) {
  long long d = num[1].first - num[0].first;
  for (int i = 1; i < (int)num.size(); ++i) {
    if (num[i].first - num[i - 1].first != d) {
      return 0;
    }
  }
  return 1;
}
int main() {
  int n;
  cin >> n;
  vector<pair<long long, int> > num(n);
  for (int i = 0; i < n; ++i) {
    cin >> num[i].first;
    num[i].second = i + 1;
  }
  if (n <= 3) {
    cout << 1 << endl;
    return 0;
  }
  sort(num.begin(), num.end());
  vector<pair<long long, int> > temp = num;
  temp.erase(temp.begin());
  if (ap(temp)) {
    cout << num[0].first << endl;
    return 0;
  }
  temp = num;
  temp.erase(temp.begin() + 1);
  if (ap(temp)) {
    cout << num[0].second << endl;
    return 0;
  }
  long long d = num[1].first - num[0].first, ans = -1, cnt = 0,
            b = num[0].first;
  for (int i = 1; i < n; ++i) {
    if (num[i].first - num[i - 1].first != d) {
      if (i < n - 1) {
        i++;
        bool flag = 1;
        if (num[i].first - num[i - 2].first == d) {
          for (int j = i + 1; j < (int)num.size(); ++j) {
            if (num[j].first - num[j - 1].first != d) {
              flag = 0;
              break;
            }
          }
          if (flag) {
            ans = num[i - 1].second;
          } else {
            ans = -1;
          }
          break;
        } else {
          ans = -1;
          break;
        }
      } else {
        ans = num[i].second;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
