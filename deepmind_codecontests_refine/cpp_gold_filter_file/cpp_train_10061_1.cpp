#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXI = 1024 * 1024;
bool used[MAXI];
bool used2[MAXI];
vector<int> simpleNums;
int maxSimpleDel[MAXI];
int main() {
  for (int i = 0; i <= 1000000; i++) {
    used[i] = 0;
    used2[i] = 0;
    maxSimpleDel[i] = 0;
  }
  for (int i = 2; i <= 1000000; i++) {
    if (!used[i])
      for (int j = i + i; j <= 1000000; j += i) {
        used[j] = 1;
        maxSimpleDel[j] = i;
      }
  }
  for (int i = 2; i < 1000000; i++) {
    if (!used[i]) simpleNums.push_back(i);
  }
  int x2;
  cin >> x2;
  int x0 = x2;
  for (int i = 0; i < simpleNums.size() && simpleNums[i] <= x2; i++) {
    if (x2 % simpleNums[i]) continue;
    int x1 = x2 - simpleNums[i];
    for (int j = x1 + 1; j <= x2; j++) {
      if (used2[j]) continue;
      x0 = (x0 < j - maxSimpleDel[j] + 1) ? x0 : j - maxSimpleDel[j] + 1;
      used2[j] = 1;
    }
  }
  cout << x0 << endl;
  return 0;
}
