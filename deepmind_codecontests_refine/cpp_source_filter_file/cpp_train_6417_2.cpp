#include <bits/stdc++.h>
using namespace std;
vector<string> v;
void findNDigitNumsUtil(int n, int sum, char* out, int index) {
  if (index > n || sum < 0) return;
  if (index == n) {
    if (sum == 0) {
      out[index] = '\0';
      v.push_back(out);
    }
    return;
  }
  for (int i = 0; i <= 9; i++) {
    out[index] = i + '0';
    findNDigitNumsUtil(n, sum - i, out, index + 1);
  }
}
void findNDigitNums(int n, int sum) {
  char out[n + 1];
  for (int i = 1; i <= 9; i++) {
    out[0] = i + '0';
    findNDigitNumsUtil(n, sum - i, out, 1);
  }
}
int main() {
  int n;
  cin >> n;
  int sum = 10;
  for (int i = 2; i <= 5; i++) {
    findNDigitNums(i, sum);
  }
  for (int i = 0; i < v.size(); i++) {
    if (i == n - 1) {
      cout << v[i];
      break;
    }
  }
  return 0;
}
