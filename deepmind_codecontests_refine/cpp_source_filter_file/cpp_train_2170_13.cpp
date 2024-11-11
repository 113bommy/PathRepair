#include<bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  int a[n];
  for(int i = 0; i < n; i++) cin >> a[i];
  int sub = 1;
  for(int i _ 0; i < n; i++) {
    if(a[i] % 2 == 0) sub *= 2;
  }
  cout << pow(2, n) - sub << endl;
}