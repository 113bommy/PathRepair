#include <bits/stdc++.h>
using namespace std;
long long int mpow(long long int base, long long int exp);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int a = 0, b = 0, c = 0, d = 0, e = 0, p = 0, q = 0, r = 0;
  long long int ans = 0, res = 0, cnt = 0, sum = 0, diff = 0, mul = 1, val = 0;
  string s;
  long long int n, m, k;
  cin >> n;
  long long int arr[n + 1], brr[n + 1];
  set<long long int> st;
  set<long long int> q1, q2, q3, q4, q5;
  for (long long int i = 0; i < n; i++) {
    cin >> arr[i];
    st.insert(arr[i]);
  }
  map<long long int, long long int> mp;
  for (long long int i = 0; i < n; i++) mp[arr[i]]++;
  for (long long int i = 0; i < n; i++)
    if (mp[arr[i]] >= 8)
      q5.insert(arr[i]);
    else if (mp[arr[i]] >= 6)
      q1.insert(arr[i]);
    else if (mp[arr[i]] >= 4)
      q2.insert(arr[i]);
    else if (mp[arr[i]] >= 2)
      q3.insert(arr[i]);
    else
      q4.insert(arr[i]);
  cin >> m;
  while (m--) {
    char ss;
    cin >> ss >> a;
    if (ss == '+') {
      auto r1 = q1.find(a);
      auto r2 = q2.find(a);
      auto r3 = q3.find(a);
      auto r4 = q4.find(a);
      auto r5 = q5.find(a);
      if (r1 != q1.end()) {
        if (mp[a] == 7) {
          q1.erase(a);
          q5.insert(a);
        }
      } else if (r2 != q2.end()) {
        if (mp[a] == 5) {
          q2.erase(a);
          q1.insert(a);
        }
      } else if (r3 != q3.end()) {
        if (mp[a] == 3) {
          q3.erase(a);
          q2.insert(a);
        }
      } else if (r4 != q4.end()) {
        if (mp[a] == 1) {
          q4.erase(a);
          q3.insert(a);
        }
      } else if (r5 != q5.end()) {
        q4.insert(a);
      }
      mp[a]++;
      if ((q5.size() >= 1) || (q1.size() >= 2) ||
          (q1.size() == 1 && (q2.size() >= 1 || q3.size() >= 1)) ||
          (q2.size() == 1 && q3.size() >= 2) || (q2.size() >= 2))
        cout << "YES" << '\n';
      else
        cout << "NO" << '\n';
    } else {
      auto r1 = q1.find(a);
      auto r2 = q2.find(a);
      auto r3 = q3.find(a);
      auto r4 = q4.find(a);
      auto r5 = q5.find(a);
      if (r5 != q5.end()) {
        if (mp[a] == 8) {
          q5.erase(a);
          q1.insert(a);
        }
      }
      if (r1 != q1.end()) {
        if (mp[a] == 6) {
          q1.erase(a);
          q2.insert(a);
        }
      }
      if (r2 != q2.end()) {
        if (mp[a] == 4) {
          q2.erase(a);
          q3.insert(a);
        }
      }
      if (r3 != q3.end()) {
        if (mp[a] == 2) {
          q3.erase(a);
          q4.insert(a);
        }
      }
      mp[a]--;
      if ((q5.size() >= 1) || (q1.size() >= 2) ||
          (q1.size() == 1 && (q2.size() >= 1 || q3.size() >= 1)) ||
          (q2.size() == 1 && q3.size() >= 2) || (q2.size() >= 2))
        cout << "YES" << '\n';
      else
        cout << "NO" << '\n';
    }
  }
  return 0;
}
