#include <bits/stdc++.h>
using namespace std;
long long int min(long long int a, long long int b) {
  if (a < b) {
    return a;
  } else {
    return b;
  }
}
long long int max(long long int a, long long int b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string str;
    cin >> str;
    if (n == 1) {
      cout << 1 << "\n";
      continue;
    }
    if (n == 2) {
      if (str[0] == str[1]) {
        cout << 1 << "\n";
        continue;
      }
    }
    vector<long long int> seg;
    long long int curr_length = 1;
    for (long long int i = 0; i < str.size() - 1; i++) {
      if (str[i] == str[i + 1]) {
        curr_length++;
      } else {
        seg.push_back(curr_length);
        curr_length = 1;
      }
    }
    seg.push_back(curr_length);
    long long int segtillnow = 0;
    long long int ans = 0;
    for (long long int i = 0; i < seg.size(); i++) {
      segtillnow++;
      if (seg[i] == 1) {
        continue;
      } else if (seg[i] > 1) {
        long long int operations = min(seg[i] - 1, segtillnow);
        ans += operations;
        segtillnow -= operations;
      }
    }
    ans += ((segtillnow + 1) / 2);
    cout << ans << "\n";
  }
}
