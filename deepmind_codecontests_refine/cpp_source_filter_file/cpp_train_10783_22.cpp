#include <bits/stdc++.h>
using namespace std;
bool twopointers(int A[], int left, int right, int value) {
  if (left < 0 || right >= 10) return 0;
  if (A[left] + A[right] == value) return 1;
  if (A[left] + A[right] < value)
    return twopointers(A, left + 1, right, value);
  else
    return twopointers(A, left, right - 1, value);
}
int MaxWindow(int number, int Arr[], int fullnumber) {
  int sum = 0;
  int p1 = 0;
  int p2 = number;
  for (int i = 0; i < number; i++) sum += Arr[i];
  int counter = 0;
  while (p2 != fullnumber) {
    sum = max(sum, sum - Arr[p1] + Arr[p2]);
    p2++, p1++;
  }
  return sum;
}
int Maxsubsequence(int number, int exceed, int Arr[]) {
  int l = 0, r = 0;
  int count = 0;
  int sum = 0, ans = -100;
  while (l < number) {
    while (r < number && Arr[r] + sum <= exceed) {
      sum += Arr[r];
      r++;
    }
    ans = max(sum, ans);
    sum -= Arr[l];
    l++;
  }
  return ans;
}
int Arr[100];
int i = 0;
void Getnumber(long long number) {
  while (number) {
    if (number % 10 != 1 && number % 10 != 0) {
      Arr[i] = number % 10;
      i++;
    }
    number /= 10;
  }
}
bool isprime(int number) {
  if (number == 2) return true;
  if (number % 2 == 0) return false;
  for (int i = 3; i < number; i += 2)
    if (number % i == 0) return false;
  return true;
}
int main() {
  long long n, k;
  cin >> n >> k;
  long long ans = 0;
  long long left = 1, right = 1e9, mid;
  long long ans1 = k;
  if (k >= n) {
    cout << k << endl;
    return 0;
  }
  n -= k;
  while (left < right) {
    mid = (left + right) / 2;
    if ((mid) * (mid + 1) / 2 >= n) {
      ans = mid;
      right = mid;
    } else
      left = mid + 1;
  }
  cout << ans1 + ans << endl;
}
