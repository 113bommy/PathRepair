#include <bits/stdc++.h>
using namespace std;
int card[12] = {0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 15, 4};
int n, ways;
int main() {
  cin >> n;
  n -= 10;
  cout << card[n];
}
