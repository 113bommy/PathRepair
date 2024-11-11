#include <bits/stdc++.h>
using namespace std;
int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
void CI(int &_x) { scanf("%d", &_x); }
void CO(int &_x) { cout << _x; }
template <typename T>
void getarray(T a[], int n) {
  for (int i = 0; i < n; i++) cin >> a[i];
}
template <typename T>
void printarray(T a[], int n) {
  for (int i = 0; i < n - 1; i++) cout << a[i] << " ";
  cout << a[n - 1] << endl;
}
const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
int dr8[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc8[8] = {0, 0, -1, 1, 1, 1, -1, -1};
int dr4[4] = {0, 0, 1, -1};
int dc4[4] = {-1, 1, 0, 0};
int kn8r[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int kn8c[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int main() {
  long long int num, kount = 0, first = -1, second = -1;
  cin >> num;
  if (num == 1) {
    cout << 1 << "\n" << 0 << "\n";
    return 0;
  }
  for (long long int i = 2; i * i <= num; i++) {
    while (num % i == 0) {
      num = num / i;
      kount++;
      if (first == -1)
        first = i;
      else if (first != -1)
        second = i;
    }
  }
  if (num > 1) {
    kount++;
    if (first == -1)
      first = num;
    else if (first != -1)
      second = num;
  }
  if (kount == 2) {
    cout << 2 << "\n";
  } else {
    cout << 1 << "\n";
    if (first * second < 0)
      cout << "0\n";
    else
      cout << first * second << "\n";
  }
}
