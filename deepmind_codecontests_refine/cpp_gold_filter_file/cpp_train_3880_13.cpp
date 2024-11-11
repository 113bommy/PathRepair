#include <bits/stdc++.h>
using namespace std;
int INT_MAX_VAL = (int)1e20;
int INT_MIN_VAL = (int)-1e20;
long long LONG_MAX_VAL = (long long)1e20;
long long LONG_MIN_VAL = (long long)-1e20;
int main() {
  string s;
  cin >> s;
  vector<long long> cnt(10);
  for (int i = 0; i < s.size(); i++) {
    cnt[s[i] - '0']++;
  }
  vector<long long> r_one;
  vector<long long> r_two;
  long long max = -1;
  for (int i = 1; i <= 5; i++) {
    vector<long long> one;
    vector<long long> two;
    vector<long long> cnt_one = cnt;
    vector<long long> cnt_two = cnt;
    long long cur = 0;
    if (cnt[i] > 0 && cnt[(10 - i) % 10] > 0) {
      one.push_back(i);
      cnt_one[i]--;
      two.push_back((10 - i) % 10);
      cnt_two[(10 - i) % 10]--;
      cur++;
    } else {
      continue;
    }
    for (int i = 0; i <= 9; i++) {
      while (cnt_one[i] > 0 && cnt_two[9 - i] > 0) {
        one.push_back(i);
        two.push_back(9 - i);
        cnt_one[i]--;
        cnt_two[9 - i]--;
        cur++;
      }
    }
    reverse(one.begin(), one.end());
    reverse(two.begin(), two.end());
    for (int i = 0; i < min(cnt_one[0], cnt_two[0]); i++) {
      one.push_back(0);
      two.push_back(0);
      cur++;
    }
    long long m = min(cnt_one[0], cnt_two[0]);
    cnt_one[0] -= m;
    cnt_two[0] -= m;
    reverse(one.begin(), one.end());
    reverse(two.begin(), two.end());
    for (int i = 0; i <= 9; i++) {
      while (cnt_one[i] > 0) {
        one.push_back(i);
        cnt_one[i]--;
      }
      while (cnt_two[i] > 0) {
        two.push_back(i);
        cnt_two[i]--;
      }
    }
    if (cur > max) {
      r_one = one;
      r_two = two;
      max = cur;
    }
  }
  if (max == -1) {
    for (int i = 0; i <= 9; i++) {
      while (cnt[i] > 0) {
        r_one.push_back(i);
        r_two.push_back(i);
        cnt[i]--;
      }
    }
  }
  for (int i = r_one.size() - 1; i >= 0; i--) {
    cout << r_one[i];
  }
  cout << '\n';
  for (int i = r_two.size() - 1; i >= 0; i--) {
    cout << r_two[i];
  }
  cout << '\n';
  return 0;
}
