#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (a == 0) return b;
  return (b % a, a);
}
int binarysearch(int a[], int ele, int n) {
  int beg = 0, end = n, mid, ans;
  while (beg <= end) {
    mid = beg + (end - beg) / 2;
    if (a[mid] > ele) {
      ans = mid;
      end = mid - 1;
    } else
      beg = mid + 1;
  }
  return ans;
}
bool checkpallin(string a) {
  int i = 0, j = a.length() - 1;
  while (i < j) {
    if (a[i] != a[j]) return false;
    i++, j--;
  }
  return true;
}
bool comp(string a, string b) { return a.length() < b.length(); }
int main(void) {
  int n, a;
  cin >> n >> a;
  cout << (a & 1) ? (1 + a / 2) : (1 + (n - a) / 2);
  return 0;
}
