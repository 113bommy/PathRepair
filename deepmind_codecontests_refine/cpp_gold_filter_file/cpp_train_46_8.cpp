#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long s1 = 0, s2 = 0, s3 = 0;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    s1 += num;
  }
  for (int i = 0; i < n - 1; i++) {
    int num;
    cin >> num;
    s2 += num;
  }
  for (int i = 0; i < n - 2; i++) {
    int num;
    cin >> num;
    s3 += num;
  }
  cout << s1 - s2 << endl << s2 - s3;
  return 0;
}
