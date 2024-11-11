#include <bits/stdc++.h>
using namespace std;
string ConvertToBin(long long s) {
  string res = "";
  while (s != 0) {
    res += (char)('0' + s % 2);
    s /= 2;
  }
  reverse(res.begin(), res.end());
  return res;
}
void PrintVec(vector<int> &v) {
  for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    cout << *it << " ";
}
vector<int> Populate(vector<int> &v, int n) {
  int num;
  for (int i = 0; i < n; i++) {
    cin >> num;
    v.push_back(num);
  }
  return (v);
}
int sumofdigits(int n) {
  int sm = 0;
  while (n) {
    sm = sm + (n - (n / 10) * 10);
    n = n / 10;
  }
  return (sm);
}
bool isprime(int n) {
  int i = 0;
  for (i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return (false);
  }
  return (true);
}
int main() {
  int n, i, j, count = 0, count2 = 0, min = 1000000;
  cin >> n;
  int arr[n];
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int ar[43];
  for (i = 0; i < 43; i++) {
    if (i == 4 || i == 8 || i == 15 || i == 16 || i == 23 || i == 42)
      ar[i] = 0;
    else
      ar[i] = 1000000;
  }
  for (i = 0; i < n; i++) {
    ar[arr[i]]++;
    for (j = 3; j <= arr[i] - 1; j++) {
      if (ar[j] < ar[arr[i]]) {
        ar[arr[i]]--;
        count++;
      }
    }
  }
  for (i = 0; i < 43; i++) {
    if (ar[i] < min) min = ar[i];
  }
  for (i = 0; i < 43; i++) {
    if (ar[i] != 1000000) count2 = count2 + (ar[i] - min);
  }
  cout << count + count2;
  return (0);
}
