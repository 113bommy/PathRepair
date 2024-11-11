#include <bits/stdc++.h>
using namespace std;
std::map<long long int, long long int> m;
long long int search(long long int a[], long long int n, long long int x) {
  for (int i = 0; i < n; i++) {
    if (a[i] == x) return i;
  }
  return -1;
}
bool contain(string a, string b) {
  if (a.find(b) != std::string::npos) return 1;
  return 0;
}
void given(long long int a[], long long int n) {
  for (int i = 0; i < n; i++) cin >> a[i];
  ;
}
void print(long long int a[], long long int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i];
    ;
    cout << " ";
    ;
  }
}
void maping(long long int a[], long long int n) {
  for (int i = 0; i < n; i++) m[a[i]]++;
}
long long int power(long long int x, long long int y) {
  if (y == 0)
    return 1;
  else if (y % 2 == 0)
    return power(x, y / 2) * power(x, y / 2);
  else
    return x * power(x, y / 2) * power(x, y / 2);
}
long long int min(long long int a, long long int b) {
  if (a < b) return a;
  return b;
}
long long int max(long long int a, long long int b) {
  if (a < b) return b;
  return a;
}
int main() {
  long long int n;
  cin >> n;
  ;
  long long int a[n];
  given(a, n);
  if (n == 1) {
    cout << "-1";
    return 0;
  }
  sort(a, a + n);
  long long int d = min(a[1] - a[0], a[2] - a[1]);
  long long int flag = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] - a[i - 1] != d) {
      if (a[i] - a[i - 1] == 2 * d && flag == 0)
        flag = i - 1;
      else {
        cout << "0";
        return 0;
      }
    }
  }
  if (flag != 0) {
    cout << "1";
    cout << endl;
    ;
    cout << a[flag] + d;
    return 0;
  }
  if (n == 2 && d != 0 && !(d % 2)) {
    cout << "3";
    cout << endl;
    ;
    cout << a[0] - d;
    cout << " ";
    ;
    cout << a[0] + d / 2;
    cout << " ";
    ;
    cout << a[1] + d;
    return 0;
  } else if (d == 0) {
    cout << "1";
    cout << endl;
    ;
    cout << a[0];
    return 0;
  } else {
    cout << "2";
    cout << endl;
    ;
    cout << a[0] - d;
    cout << " ";
    ;
    cout << a[n - 1] + d;
    cout << " ";
    ;
  }
}
