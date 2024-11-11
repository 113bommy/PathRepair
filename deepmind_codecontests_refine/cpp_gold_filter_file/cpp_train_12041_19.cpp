#include <bits/stdc++.h>
using namespace std;
vector<int> vec[100010];
void test2(int n) {
  for (int i = 0; i < n - 1; i++) {
    cout << 1 << " " << i + 2 << "\n";
  }
}
int main() {
  int n;
  cin >> n;
  if (n == 2 || n == 3 || n == 4 || n == 5) {
    cout << -1 << "\n";
  } else {
    cout << 1 << " " << 2 << "\n";
    int left = n - 2;
    int iCnt = 3;
    for (int i = 0; i < (left / 2); i++) {
      cout << 2 << " " << iCnt << "\n";
      iCnt++;
    }
    for (int i = (left / 2); i < left; i++) {
      cout << 3 << " " << iCnt << "\n";
      iCnt++;
    }
  }
  test2(n);
  return 0;
}
