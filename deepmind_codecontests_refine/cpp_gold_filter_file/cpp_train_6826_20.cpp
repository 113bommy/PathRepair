#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string str, t;
  long long MAX = INT_MIN;
  cin >> n;
  int arr[50], s, u;
  for (int i = 0; i < n; i++) {
    cin >> str >> s >> u;
    int x;
    long long sum = 0;
    for (int i = 0; i < 5; i++) {
      cin >> x;
      sum += x;
    }
    sum += (s * 100) - (u * 50);
    if (sum > MAX) {
      MAX = sum;
      t = str;
    }
  }
  cout << t << endl;
}
