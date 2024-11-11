#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> vec1(n), vec2(n);
  map<long long, long long> l, r;
  for (int i = 0; i < n; i++) {
    cin >> vec1[i];
    vec2[i] = vec1[i];
    r[vec1[i]]++;
  }
  sort(vec1.begin(), vec1.end());
  long long m1, m2, m3, m, ans = 0;
  if (vec1[0] == vec1[1] == vec1[2]) {
    m = vec1[0];
    for (int i = 0; i < n; i++) {
      if (vec2[i] == m) {
        r[m]--;
        l[m]++;
        long long temp = r[m];
        ans += (temp * (temp - 1)) / 2;
      }
    }
  } else {
    m1 = vec1[0];
    m2 = vec1[1];
    m3 = vec1[2];
    for (int i = 0; i < n; i++) {
      if (vec2[i] == m1) {
        r[m1]--;
        l[m1]++;
        long long temp1 = r[m2], temp2 = r[m3];
        if (m2 == m3) {
          ans += (temp1 * (temp1 - 1)) / 2;
        } else {
          if (temp1 >= 0 && temp2 >= 0) ans += temp1 * temp2;
        }
      } else if (vec2[i] == m2) {
        r[m2]--;
        l[m2]++;
        long long temp1 = r[m1], temp2 = r[m3];
        if (m1 == m3) {
          ans += (temp1 * (temp1 - 1)) / 2;
        } else {
          if (temp1 >= 0 && temp2 >= 0) ans += temp1 * temp2;
        }
      } else if (vec2[i] == m3) {
        r[m3]--;
        l[m3]++;
        long long temp1 = r[m1], temp2 = r[m2];
        if (m1 == m2) {
          ans += (temp1 * (temp1 - 1)) / 2;
        } else {
          if (temp1 >= 0 && temp2 >= 0) ans += temp1 * temp2;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
