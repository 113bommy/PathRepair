#include <bits/stdc++.h>
using namespace std;
int ans[] = {1, 18, 1800, 670320, 734832000, 890786230, 695720788, 150347555};
int main() {
  int n;
  cin >> n;
  cout << (n % 2 ? ans[n / 2] : 0) << endl;
}
