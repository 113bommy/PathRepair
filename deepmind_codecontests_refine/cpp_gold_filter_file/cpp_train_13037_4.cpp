#include <bits/stdc++.h>
using namespace std;
int power(int x, unsigned int y) {
  int res = 1;
  while (y > 0) {
    if (y & 1) {
      res = res * x;
    }
    y = y >> 1;
    x = x * x;
  }
  return res;
}
int powermod(int x, unsigned int y, int p) {
  int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) {
      res = (res * x) % p;
    }
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
using namespace std;
int32_t main() {
  int t, n, arr[100005], fr, ba, cf, cb, ele, freq, ans;
  cin >> t;
  while (t--) {
    cin >> n;
    ans = 1;
    for (int i = (int)(0); i < (int)(n); i++) {
      cin >> arr[i];
    }
    for (int i = (int)(1); i < (int)(201); i++) {
      cf = 0;
      cb = 0;
      set<pair<int, int> > ml;
      map<int, int> mp;
      fr = 0;
      ba = n - 1;
      for (int j = (int)(0); j < (int)(n); j++) {
        mp[arr[j]] += 1;
      }
      for (auto &val : mp) {
        ans = max(ans, val.second);
        ml.insert({-val.second, val.first});
      }
      while (fr <= ba) {
        while (fr <= ba and arr[fr] != i) {
          freq = mp[arr[fr]];
          ml.erase({-freq, arr[fr]});
          mp[arr[fr]] -= 1;
          freq -= 1;
          ml.insert({-freq, arr[fr]});
          fr += 1;
        }
        if (fr <= ba) {
          freq = mp[arr[fr]];
          ml.erase({-freq, arr[fr]});
          mp[arr[fr]] -= 1;
          freq -= 1;
          ml.insert({-freq, arr[fr]});
          fr += 1;
          cf += 1;
        }
        while (fr <= ba and arr[ba] != i) {
          freq = mp[arr[ba]];
          ml.erase({-freq, arr[ba]});
          mp[arr[ba]] -= 1;
          freq -= 1;
          ml.insert({-freq, arr[ba]});
          ba -= 1;
        }
        if (fr <= ba) {
          freq = mp[arr[ba]];
          ml.erase({-freq, arr[ba]});
          mp[arr[ba]] -= 1;
          freq -= 1;
          ml.insert({-freq, arr[ba]});
          ba -= 1;
          cb += 1;
          ans = max(ans, cf + cb - ml.begin()->first);
        }
      }
    }
    cout << ans << endl;
  }
}
