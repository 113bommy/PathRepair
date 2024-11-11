#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  string s;
  cin >> s;
  string z;
  int sum = 0;
  for (int i = 0; sum < N - i; i++) {
    sum += i;
    cout << s[sum];
  }
}
