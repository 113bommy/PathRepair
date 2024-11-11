#include <bits/stdc++.h>
using namespace std;
int n;
string s1, s2, s3;
int fix[10001];
int fix2[10001];
int fix3[10001];
int main() {
  cin >> n;
  cin >> s1 >> s2 >> s3;
  int max1 = 0, max2 = 0, max3 = 0;
  for (int i = 0; i < s1.length(); i++) {
    fix[s1[i] - 'A']++;
    max1 = max(fix[s1[i] - 'A'], max1);
  }
  for (int i = 0; i < s2.length(); i++) {
    fix2[s2[i] - 'A']++;
    max2 = max(fix2[s2[i] - 'A'], max2);
  }
  for (int i = 0; i < s3.length(); i++) {
    fix3[s3[i] - 'A']++;
    max3 = max(fix3[s3[i] - 'A'], max3);
  }
  if (max1 != s1.length()) {
    int l1 = s1.length();
    max1 = min(max1 + n, l1);
  } else {
    if (n > 1) {
      max1 = s1.length();
    } else {
      max1--;
    }
  }
  if (max2 != s2.length()) {
    int l2 = s1.length();
    max2 = min(max2 + n, l2);
  } else {
    if (n > 1) {
      max2 = s2.length();
    } else {
      max2--;
    }
  }
  if (max3 != s3.length()) {
    int l3 = s3.length();
    max3 = min(max3 + n, l3);
  } else {
    if (n > 1) {
      max3 = s3.length();
    } else {
      max3--;
    }
  }
  if (max1 > max2 && max1 > max3) {
    cout << "Kuro" << endl;
    return 0;
  }
  if (max2 > max1 && max2 > max3) {
    cout << "Shiro" << endl;
    return 0;
  }
  if (max3 > max1 && max3 > max2) {
    cout << "Katie" << endl;
    return 0;
  }
  cout << "Draw" << endl;
  return 0;
  return 0;
}
