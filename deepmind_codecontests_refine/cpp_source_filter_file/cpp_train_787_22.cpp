#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  int flag = 0, flag2 = 0;
  long long int n = s1.size();
  string s3;
  sort(s1.begin(), s1.end());
  sort(s2.rbegin(), s2.rend());
  long long int i;
  for (i = 0; i <= n / 2; i++) {
    if (s1[i] >= s2[i]) {
      if (i != 0 && s2[i - 1] <= s1[i]) flag = 1;
      break;
    }
    s3.push_back(s1[i]);
    if (s3.size() == n) {
      flag2 = 1;
      break;
    }
    s3.push_back(s2[i]);
  }
  if (flag == 0 && flag2 == 0) {
    if (n % 2 == 0) {
      for (long long int j = i; j < n / 2; j++) {
        s3.push_back(s2[j]);
        s3.push_back(s1[j]);
      }
    } else {
      for (long long int j = i; j < n / 2; j++) {
        s3.push_back(s1[j]);
        s3.push_back(s2[j]);
      }
      if (i < n / 2 || n == 1) {
        s3.push_back(s1[n / 2]);
      }
    }
  }
  if (flag != 0 && flag2 == 0) {
    if (n % 2 == 0) {
      for (long long int j = i; j < n / 2; j++) {
        s3.push_back(s1[j]);
        s3.push_back(s2[j]);
      }
    } else {
      s3.erase(--s3.end());
      for (long long int j = i; j <= n / 2; j++) {
        s3.push_back(s1[j]);
        s3.push_back(s2[j - 1]);
      }
    }
  }
  for (int l = 0; i < n; i++) cout << s3[l];
}
