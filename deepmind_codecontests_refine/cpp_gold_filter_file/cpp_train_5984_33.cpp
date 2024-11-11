#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
  string s;
  int a[10000];
  for (int i = 0; i < 10000; i++) {
    a[i] = 0;
  }
  long long cnt = 0;
  getline(cin, s);
  for (int i = 0; i < s.length(); i++) {
    a[s[i]]++;
  }
  for (int i = 0; i < 10000; i++) {
    cnt += (long long)a[i] * a[i];
  }
  cout << cnt;
  return 0;
}
