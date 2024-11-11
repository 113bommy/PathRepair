#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long q;
  cin >> q;
  for (long long i = 0; i < q; i++) {
    long long n;
    cin >> n;
    long long zero = 0;
    vector<long long> len;
    long long one = 0;
    for (long long j = 0; j < n; j++) {
      string s;
      cin >> s;
      for (long long k = 0; k < s.size(); k++) {
        if (s[k] == '1') {
          one++;
        } else {
          zero++;
        }
      }
      len.push_back(s.size());
    }
    sort(len.begin(), len.end());
    vector<long long> zero_v;
    vector<long long> one_v;
    long long ind = -1;
    for (long long j = 0; j < len.size(); j++) {
      if (len[j] <= zero) {
        zero -= len[j];
        zero_v.push_back(len[j]);
      } else {
        ind = j;
        break;
      }
    }
    for (long long j = ind + 1; j < len.size(); j++) {
      one_v.push_back(len[j]);
    }
    if (zero == 0) {
      cout << n << "\n";
    } else {
      if (len[ind] % 2 == 0) {
        if (zero % 2 == 0) {
          cout << n << "\n";
        } else {
          bool r = false;
          for (long long j = 0; j < zero_v.size(); j++) {
            if (zero_v[j] % 2 == 1) {
              cout << n << "\n";
              r = true;
              break;
            }
          }
          if (!r) {
            for (long long j = 0; j < one_v.size(); j++) {
              if (one_v[j] % 2 == 1) {
                cout << n << "\n";
                r = true;
                break;
              }
            }
            if (!r) {
              cout << n - 1 << "\n";
            }
          }
        }
      } else {
        cout << n << "\n";
      }
    }
  }
  return 0;
}
