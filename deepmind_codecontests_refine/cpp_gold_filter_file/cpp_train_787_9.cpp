#include <bits/stdc++.h>
using namespace std;
int getMaxi(vector<int>& vec) {
  for (int i = vec.size() - 1; i >= 0; --i) {
    if (vec[i] > 0) {
      return i;
    }
  }
}
int getMini(vector<int>& vec) {
  for (long long int i = (0); i < (long long int)(vec.size()); ++i) {
    if (vec[i] > 0) {
      return i;
    }
  }
}
int main() {
  long long int n;
  string x, y;
  cin >> x >> y;
  n = x.length();
  vector<int> s(40, 0);
  vector<int> p(40, 0);
  int mini = 99;
  int maxi = -1;
  for (char a : x) {
    s[a - 'a']++;
  }
  int cnt = n / 2, tmpcnt = n / 2;
  for (int i = s.size() - 1; i >= 0; --i) {
    if (cnt <= 0) break;
    if (s[i] > 0) {
      tmpcnt = cnt;
      cnt -= s[i];
      s[i] -= tmpcnt;
      s[i] = max(s[i], 0);
    }
  }
  for (char a : y) {
    p[a - 'a']++;
  }
  cnt = tmpcnt = n / 2 + n % 2;
  for (long long int i = (0); i < (long long int)(s.size() - 1); ++i) {
    if (cnt <= 0) break;
    if (p[i] > 0) {
      tmpcnt = cnt;
      cnt -= p[i];
      p[i] -= tmpcnt;
      p[i] = max(p[i], 0);
    }
  }
  vector<char> res(n);
  long long int begin = 0, end = n - 1;
  for (long long int i = (0); i < (long long int)(n); ++i) {
    mini = getMini(s);
    maxi = getMaxi(p);
    if (i & 1) {
      if (mini < maxi) {
        res[begin] = maxi;
        --p[maxi];
        ++begin;
      } else {
        res[end] = getMini(p);
        --p[getMini(p)];
        --end;
      }
    } else {
      if (mini < maxi) {
        res[begin] = mini;
        --s[mini];
        ++begin;
      } else {
        res[end] = getMaxi(s);
        --s[getMaxi(s)];
        --end;
      }
    }
  }
  for (char i : res) cout << (char)(i + 'a');
  cout << endl;
  return 0;
}
