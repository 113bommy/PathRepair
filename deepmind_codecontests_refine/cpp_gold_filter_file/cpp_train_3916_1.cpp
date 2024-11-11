#include <bits/stdc++.h>
using namespace std;
int n, k;
int main(void) {
  cin >> n >> k;
  vector<int> s(k);
  int mid = n, side = n * 2, lone = 0;
  for (int i = 0; i < k; i++) cin >> s[i];
  for (int i = 0; i < k; i++) {
    while (s[i] >= 4) {
      if (mid) {
        s[i] -= 4;
        mid--;
      } else if (side >= 2) {
        s[i] -= 4;
        side -= 2;
      } else
        goto no;
    }
  }
  for (int i = 0; i < k; i++) {
    if (s[i] == 3) {
      if (mid) {
        s[i] -= 3;
        mid--;
      } else if (side >= 2) {
        s[i] -= 3;
        side -= 2;
      } else {
        s[i] = 1;
        s.push_back(1);
        s.push_back(1);
      }
    }
    if (s[i] == 2) {
      if (side) {
        s[i] -= 2;
        side--;
      } else if (mid) {
        lone++;
        mid--;
        s[i] -= 2;
      } else {
        s[i] = 1;
        s.push_back(1);
      }
    }
  }
  for (int i = 0; i < s.size(); i++) {
    if (s[i]) {
      if (mid) {
        s[i] = 0;
        mid--;
        lone++;
      } else if (side) {
        side--;
        s[i] = 0;
      } else if (lone) {
        lone--;
        s[i] = 0;
      } else
        goto no;
    }
  }
  cout << "YES" << endl;
  goto end;
no:
  cout << "NO" << endl;
end:
  return 0;
}
