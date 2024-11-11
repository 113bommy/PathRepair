#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
using namespace std;
template <typename T>
T max1(T a, T b) {
  return a > b ? a : b;
}
template <typename T>
T min1(T a, T b) {
  return a < b ? a : b;
}
template <typename T>
T max1(T a, T b, T c) {
  return max1(a, max1(b, c));
}
template <typename T>
T min1(T a, T b, T c) {
  return min1(a, min1(b, c));
}
template <typename T>
T abs1(T a, T b) {
  return a > b ? a - b : b - a;
}
template <typename T>
void swap1(T &a, T &b) {
  T temp = b;
  b = a;
  a = temp;
}
template <typename T>
void swap1(T a[], int i, int j) {
  T temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}
template <typename T, typename P>
void reset(T array[], int size, P value) {
  for (int i = 0; i < (size); i++) array[i] = value;
}
template <typename T, typename P>
void reset(T *array, int rows, int cols, P value) {
  for (int i = 0; i < (rows); i++)
    for (int j = 0; j < (cols); j++) *(array + i * cols + j) = value;
}
template <typename T>
void resetClear(T v[], int size) {
  for (int i = 0; i < size; i++) v[i].clear();
}
template <typename T>
T maxArr(T array[], int start, int ending) {
  T res = array[start];
  for (int i = (start); i <= int(ending); i++) res = max1(array[i], res);
  return res;
}
template <typename T>
T maxArr(T array[], int ending) {
  T res = array[0];
  for (int i = 0; i < (ending); i++) res = max1(array[i], res);
  return res;
}
template <typename T>
T minArr(T array[], int start, int ending) {
  T res = array[start];
  for (int i = (start); i <= int(ending); i++) res = min1(array[i], res);
  return res;
}
template <typename T>
T minArr(T array[], int ending) {
  T res = array[0];
  for (int i = 0; i < (ending); i++) res = min1(array[i], res);
  return res;
}
template <typename T, typename P = long long int>
P sumArr(T array[], int ending) {
  P res = 0;
  for (int i = 0; i < (ending); i++) res = res + array[i];
  return res;
}
template <typename T, typename P = long long int>
P sumArr(T array[], int ending, P mod) {
  P res = 0;
  for (int i = 0; i < (ending); i++) res = (res + array[i]) % mod;
  return res;
}
int stringToNum(string &number) {
  int num = 0;
  int mul = 1;
  for (int i = ((int)(number.size())) - 1; i >= 0; --i) {
    num = num + (number[i] - '0') * mul;
    mul = mul * 10;
  }
  return num;
}
int bit(long long int num) {
  int res = 0;
  for (long long int i = 0; (1ll << i) <= num; ++i) res = i;
  return res;
}
const int MAXN = 100000 + 10;
const int MAXM = 100000 + 10;
const int MAXLOG = 18;
const int MY_MAX = 1000000;
int n;
int t[MAXN];
int dp[MAXN];
int floorbs(int starting, int ending, int key) {
  int lo = starting;
  int hi = ending;
  if (key <= t[lo]) return lo;
  if (key > t[hi]) return INT_MAX;
  while (lo <= hi) {
    int mid = ((lo + hi) / 2);
    int midVal = t[mid];
    int midLess = t[mid - 1];
    if (mid != starting and midLess < key and key <= midVal)
      return mid;
    else if (midVal <= key)
      lo = mid + 1;
    else
      hi = mid - 1;
  }
  return INT_MAX;
}
int sol() {
  reset(dp, MAXN, INT_MAX);
  for (int i = 0; i < (n); i++) {
    dp[i] = min(dp[i], (i == 0) ? 20 : dp[i - 1] + 20);
    if (i > 0) {
      int index = floorbs(0, i - 1, t[i] - 89);
      if (index != INT_MAX) {
        if (index == 0)
          dp[i] = min(dp[i], 50);
        else
          dp[i] = min(dp[i], dp[index - 1] + 50);
      }
      index = floorbs(0, i - 1, t[i] - 1139);
      if (index != INT_MAX) {
        if (index == 0)
          dp[i] = min(dp[i], 120);
        else
          dp[i] = min(dp[i], dp[index - 1] + 120);
      }
    }
  }
  for (int i = 0; i < (n); i++)
    if (i == 0)
      cout << dp[0] << endl;
    else
      cout << dp[i] - dp[i - 1] << endl;
  return dp[n - 1];
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 0; i < (n); i++) cin >> t[i];
  sol();
  return 0;
}
