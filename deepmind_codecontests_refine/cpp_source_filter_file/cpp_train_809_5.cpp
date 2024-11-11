#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  long long a[100000];
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  
  x = a[0];
  for (int i = 1; i < N; i++) {
    x ^= a[i];
  }
  if (x == 0) {
  	cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}