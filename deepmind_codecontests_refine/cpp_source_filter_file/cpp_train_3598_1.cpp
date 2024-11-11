#include <bits/stdc++.h>
#pragma GCC optimize("-Ofast", "-funroll-all-loops")
using namespace std;
long long int CeilIndex(std::vector<long long int>& v, long long int l,
                        long long int r, long long int key) {
  while (r - l > 1) {
    long long int m = l + (r - l) / 2;
    if (v[m] > key)
      r = m;
    else
      l = m;
  }
  return r;
}
long long int LongestIncreasingSubsequenceLength(
    std::vector<long long int>& v) {
  if (v.size() == 0) return 0;
  std::vector<long long int> tail(v.size(), 0);
  long long int length = 1;
  tail[0] = v[0];
  for (size_t i = 1; i < v.size(); i++) {
    if (v[i] < tail[0])
      tail[0] = v[i];
    else if (v[i] >= tail[length - 1])
      tail[length++] = v[i];
    else
      tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i];
  }
  return length;
}
bool check(int m, vector<pair<int, int>> v) {
  int f = 0;
  for (int i = 0; i < v.size(); i++) {
    int x = v[i].first;
    int y = v[i].second;
    if (x > m && y > m) {
      f = 1;
      break;
    }
  }
  if (f == 1)
    return false;
  else
    return true;
}
long long int subsetSumToK(long long int arr[], long long int n,
                           long long int output[][50], long long int k) {
  if (n == 0) {
    if (k == 0) {
      output[0][0] = 0;
      return 1;
    } else {
      return 0;
    }
  }
  long long int output1[1000][50];
  long long int output2[1000][50];
  long long int size1 = subsetSumToK(arr + 1, n - 1, output1, k - arr[0]);
  long long int size2 = subsetSumToK(arr + 1, n - 1, output2, k);
  long long int i, j;
  for (i = 0; i < size1; i++) {
    output[i][0] = output1[i][0] + 1;
    output[i][1] = arr[0];
  }
  for (i = 0; i < size1; i++) {
    for (j = 1; j <= output1[i][0]; j++) {
      output[i][j + 1] = output1[i][j];
    }
  }
  for (i = 0; i < size2; i++) {
    for (j = 0; j <= output2[i][0]; j++) {
      output[i + size1][j] = output2[i][j];
    }
  }
  return size1 + size2;
}
void countSubsequences(long long int arr[], long long int n,
                       long long int output[][50], long long int k) {
  int size = subsetSumToK(arr, n, output, k);
  for (long long int i = 0; i < size; i++) {
    for (long long int j = 1; j <= output[i][0]; j++) {
      cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
long long int subCount(long long int arr[], long long int n, long long int k) {
  long long int mod[k];
  memset(mod, 0, sizeof(mod));
  long long int cumSum = 0;
  for (long long int i = 0; i < n; i++) {
    cumSum += arr[i];
    mod[((cumSum % k) + k) % k]++;
  }
  long long int result = 0;
  for (long long int i = 0; i < k; i++)
    if (mod[i] > 1) result += (mod[i] * (mod[i] - 1)) / 2;
  result += mod[0];
  return result;
}
long long int fact(long long int n);
long long int nCr(long long int n, long long int r) {
  return fact(n) / (fact(r) * fact(n - r));
}
long long int fact(long long int n) {
  long long int res = 1;
  for (long long int i = 2; i <= n; i++) res = res * i;
  return res;
}
long long int subsetPairNotDivisibleByK(long long int arr[], long long int N,
                                        long long int K) {
  long long int f[K];
  memset(f, 0, sizeof(f));
  for (long long int i = 0; i < N; i++) f[arr[i] % K]++;
  if (K % 2 == 0) f[K / 2] = min(f[K / 2], 1LL);
  long long int res = min(f[0], 1LL);
  for (long long int i = 1; i <= K / 2; i++) res += max(f[i], f[K - i]);
  return res;
}
bool isPerfectSquare(long double x) {
  if (x >= 0) {
    long double sr = sqrt(x);
    return (sr * sr == x);
  }
  return false;
}
vector<long long int> v[1000001];
long long int dis[50][50];
long long int deg[1000001];
char ask(long long int x, long long int y) {
  cout << '?' << " " << x << " " << y << '\n';
  cout.flush();
  char w;
  cin >> w;
  return w;
}
bool cmp(long long int a, long long int b) {
  cout << "? " << a << " " << b << endl;
  char ch;
  cin >> ch;
  return ch == '<';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    if (n == 1)
      cout << '!' << 1 << " " << 1 << endl;
    else {
      vector<long long int> v2;
      for (long long int i = 1; i <= n; i++) v2.push_back(i);
      auto it = minmax_element(v2.begin(), v2.end(), cmp);
      cout << "! " << *it.first << ' ' << *it.second << endl;
    }
  }
  return 0;
}
