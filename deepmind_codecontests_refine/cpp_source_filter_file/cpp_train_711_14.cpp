#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n,k;
  cin >> n >> k;
  cout << k*(int)pow(k-1,n-1);
}