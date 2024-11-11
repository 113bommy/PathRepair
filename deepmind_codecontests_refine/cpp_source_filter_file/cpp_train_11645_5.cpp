#include <bits/stdc++.h>
using namespace std;
int main(){
  long long n,a,b; cin >> n >> a >> b;
  long long m = a * (n-1) + b;
  long long M = b * (n-1) + a;
  cout << max((M-m+1), 0) << endl;
  return 0;
}