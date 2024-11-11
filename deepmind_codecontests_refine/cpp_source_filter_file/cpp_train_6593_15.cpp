#include <bits/stdc++.h>
using namespace std;
int gcd(int num1, int num2) {
  if (num2 == 0) return num1;
  return gcd(num2, num1 % num2);
}
int main() {
  int n, ar = 0, br = 0;
  string a, b;
  cin >> n >> a >> b;
  int l = a.length() / gcd(a.length(), b.length()) * b.length();
  int arr[l], brr[l];
  for (int i = 0; i < l; i++) {
    arr[i] = a[i % a.length()];
  }
  for (int j = 0; j < l; j++) {
    brr[j] = b[j % b.length()];
  }
  for (int i = 0; i < l; i++) {
    if ((arr[i] == 'R' && brr[i] == 'P') || (arr[i] == 'P' && brr[i] == 'S') ||
        (arr[i] == 'S' && brr[i] == 'R')) {
      ar++;
    } else if ((arr[i] == 'R' && brr[i] == 'P') ||
               (arr[i] == 'P' && brr[i] == 'S') ||
               (arr[i] == 'S' && brr[i] == 'R')) {
      br++;
    }
  }
  ar *= n / l;
  br *= n / l;
  if (n % l != 0) {
    for (int i = 0; i < n % l; i++) {
      if ((arr[i] == 'R' && brr[i] == 'P') ||
          (arr[i] == 'P' && brr[i] == 'S') ||
          (arr[i] == 'S' && brr[i] == 'R')) {
        ar++;
      } else if ((brr[i] == 'R' && arr[i] == 'P') ||
                 (brr[i] == 'P' && arr[i] == 'S') ||
                 (brr[i] == 'S' && arr[i] == 'R')) {
        br++;
      }
    }
  }
  cout << ar << " " << br << endl;
  return 0;
}
