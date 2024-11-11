#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  long long temp = 0;
  long long a = 0, b = 0, c = 0, d = 0, p = 0;
  long long x = 0, y = 0, z = 0;
  long long n = 0, m = 0;
  long long sum = 0, res = 0, psum = 0;
  long long mid = 0, l = 0, r = 0;
  long long maxi = LONG_LONG_MIN, maxelement = 0, mini = LONG_LONG_MAX;
  long long count = 0, cnt = 0;
  long long k = 0;
  int flag = 0;
  string s, str;
  string ans;
  vector<long long>::iterator itr;
  vector<long long> vec2;
  unordered_map<long long, long long> mp;
  vector<string> vecs;
  set<long long> st;
  cin >> t;
  while (t--) {
    s.clear();
    flag = 0;
    long long cnt1 = 0, cnt2 = 0, cnt3 = 0;
    cin >> s;
    mini = LONG_LONG_MAX;
    long long i = 0, j = 0;
    n = s.size();
    while (i <= n - 3 && j < n) {
      while ((cnt1 == 0 || cnt2 == 0 || cnt3 == 0) && j < n) {
        if (s[j] == '1')
          cnt1++;
        else if (s[j] == '2')
          cnt2++;
        else
          cnt3++;
        j++;
      }
      if (cnt1 > 0 && cnt2 > 0 && cnt3 > 0) {
        flag = 1;
        cnt = j - i;
        mini = min(cnt, mini);
      }
      if (s[i] == '1')
        cnt1--;
      else if (s[i] == '2')
        cnt2--;
      else
        cnt3--;
      i++;
    }
    if (flag == 1)
      cout << mini << endl;
    else
      cout << 0 << endl;
  }
  return 0;
}
