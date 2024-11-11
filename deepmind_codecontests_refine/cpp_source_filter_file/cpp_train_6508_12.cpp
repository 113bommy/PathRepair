#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
vector<vector<unsigned long long>> def(100);
unsigned long long n, b, k, x;
void mult(vector<vector<unsigned long long>> &res,
          vector<vector<unsigned long long>> &res2) {
  vector<vector<unsigned long long>> temp(100);
  for (int i = 0; i < x; i++) temp[i].resize(x);
  for (int i = 0; i < x; i++)
    for (int j = 0; j < x; j++) temp[i][j] = 0;
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < x; j++) {
      for (int k = 0; k < x; k++) {
        int calc =
            (res[i][k] % 1000000007 * res2[k][j] % 1000000007) % 1000000007;
        temp[i][j] = (temp[i][j] % 1000000007 + calc % 1000000007) % 1000000007;
      }
    }
  }
  res = temp;
}
void vecMultiply(unsigned long long count[],
                 vector<vector<unsigned long long>> &res) {
  unsigned long long temp[x];
  memset(temp, 0, sizeof(temp));
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < x; j++) {
      int calc = (count[j] % 1000000007 * res[j][i] % 1000000007) % 1000000007;
      temp[i] = (temp[i] % 1000000007 + calc % 1000000007) % 1000000007;
    }
  }
  for (int i = 0; i < x; i++) count[i] = temp[i];
}
void matrixExponentiation(vector<vector<unsigned long long>> &res,
                          unsigned long long b) {
  if (b == 0 || b == 1) return;
  matrixExponentiation(res, b / 2);
  mult(res, res);
  if (b & 1) mult(res, def);
}
void multiplyMatrix(unsigned long long nums[]) {
  unsigned long long count[x];
  memset(count, 0, sizeof(count));
  for (int i = 0; i < n; i++) count[nums[i] % x]++;
  if (b == 1) {
    cout << count[k];
    return;
  }
  vector<vector<unsigned long long>> res = def;
  matrixExponentiation(res, b - 1);
  vecMultiply(count, res);
  cout << count[k];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> b >> k >> x;
  unsigned long long nums[n];
  for (int i = 0; i < n; i++) cin >> nums[i];
  for (int i = 0; i < x; i++) {
    def[i].resize(x);
  }
  unsigned long long freq[10];
  memset(freq, 0, sizeof(freq));
  for (int k = 0; k < n; k++) freq[nums[k]]++;
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < x; j++) {
      for (int k = 0; k < 9; k++) {
        if ((j * 10 + k) % x == i) def[j][i] += freq[k];
      }
    }
  }
  multiplyMatrix(nums);
  return 0;
}
