#include <bits/stdc++.h>
using namespace std;
bool sortcol(const vector<long long int>& v1, const vector<long long int>& v2) {
  return v1[1] < v2[1];
}
bool sortpair(const pair<char, long long int>& a,
              const pair<char, long long int>& b) {
  return a.second < b.second;
}
int main() {
  {
    long long int n, i, d, a = 0, b = 0, c = 0, j, k = 0, flag = 0, x, y, ans,
                           tt = 0;
    long long int s, m, l, xl, xxl;
    cin >> s >> m >> l >> xl >> xxl;
    cin >> n;
    unordered_map<long long int, long long int> m1;
    unordered_map<long long int, string> m2;
    vector<string> v1(n);
    m1[1] = s;
    m1[2] = m;
    m1[3] = l;
    m1[4] = xl;
    m1[5] = xxl;
    m2[1] = "S";
    m2[2] = "M";
    m2[3] = "L";
    m2[4] = "XL";
    m2[5] = "XXL";
    for (i = 0; i < n; i++) {
      string s1;
      cin >> s1;
      if (s1 == "S") a = 1;
      if (s1 == "M") a = 2;
      if (s1 == "L") a = 3;
      if (s1 == "XL") a = 4;
      if (s1 == "XXL") a = 5;
      if (a == 1) {
        if (m1[a] > 0) {
          m1[a]--;
          v1[i] = m2[a];
          continue;
        }
        if (m1[a + 1] > 0) {
          m1[a + 1]--;
          v1[i] = m2[a + 1];
          continue;
        }
        if (m1[a + 2] > 0) {
          m1[a + 2]--;
          v1[i] = m2[a + 2];
          continue;
        }
        if (m1[a + 3] > 0) {
          m1[a + 3]--;
          v1[i] = m2[a + 3];
          continue;
        }
        if (m1[a + 4] > 0) {
          m1[a + 4]--;
          v1[i] = m2[a + 4];
          continue;
        }
      }
      if (a == 5) {
        if (m1[a] > 0) {
          m1[a]--;
          v1[i] = m2[a];
          continue;
        }
        if (m1[a - 1] > 0) {
          m1[a - 1]--;
          v1[i] = m2[a - 1];
          continue;
        }
        if (m1[a - 2] > 0) {
          m1[a - 2]--;
          v1[i] = m2[a - 2];
          continue;
        }
        if (m1[a - 3] > 0) {
          m1[a - 3]--;
          v1[i] = m2[a - 3];
          continue;
        }
        if (m1[a - 4] > 0) {
          m1[a - 4]--;
          v1[i] = m2[a - 4];
          continue;
        }
      }
      if (a == 2) {
        if (m1[a] > 0) {
          m1[a]--;
          v1[i] = m2[a];
          continue;
        }
        if (m1[a + 1] > 0) {
          m1[a + 1]--;
          v1[i] = m2[a + 1];
          continue;
        }
        if (m1[a - 1] > 0) {
          m1[a - 1]--;
          v1[i] = m2[a - 1];
          continue;
        }
        if (m1[a + 2] > 0) {
          m1[a + 2]--;
          v1[i] = m2[a + 2];
          continue;
        }
        if (m1[a + 3] > 0) {
          m1[a + 3]--;
          v1[i] = m2[a + 3];
          continue;
        }
      }
      if (a == 4) {
        if (m1[a] > 0) {
          m1[a]--;
          v1[i] = m2[a];
          continue;
        }
        if (m1[a + 1] > 0) {
          m1[a + 1]--;
          v1[i] = m2[a + 1];
          continue;
        }
        if (m1[a - 1] > 0) {
          m1[a - 1]--;
          v1[i] = m2[a - 1];
          continue;
        }
        if (m1[a - 2] > 0) {
          m1[a - 2]--;
          v1[i] = m2[a - 2];
          continue;
        }
        if (m1[a - 3] > 0) {
          m1[a - 3]--;
          v1[i] = m2[a - 3];
          continue;
        }
      }
      if (a == 3) {
        if (m1[a] > 0) {
          m1[a]--;
          v1[i] = m2[a];
          continue;
        }
        if (m1[a + 1] > 0) {
          m1[a + 1]--;
          v1[i] = m2[a + 1];
          continue;
        }
        if (m1[a - 1] > 0) {
          m1[a - 1]--;
          v1[i] = m2[a - 1];
          continue;
        }
        if (m1[a + 2] > 0) {
          m1[a + 2]--;
          v1[i] = m2[a + 2];
          continue;
        }
        if (m1[a - 2] > 0) {
          m1[a - 2]--;
          v1[i] = m2[a - 2];
          continue;
        }
      }
    }
    for (auto x : v1) cout << x << "\n";
  }
  return 0;
}
