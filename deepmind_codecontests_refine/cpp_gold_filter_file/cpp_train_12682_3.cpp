#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  cout << n * ((n % 2 != 0) + 1) << endl;
}
