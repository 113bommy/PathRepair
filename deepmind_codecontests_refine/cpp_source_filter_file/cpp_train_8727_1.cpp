#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
  
  long long N;
  cin >> N;

  for(int n = 1;n <= 3500;n++) {
    for(int h = 1;h <= 3500;h++) {
      if(4*n*h-(n+h)*N > 0 && (N*n*h) % (4*n*h-(n+h)*N) == 0) {
        cout << n << " " << h << " " << N*n*h / (4*n*h-(n+h)*N) << endl;
        return 0;
      }
    }
  }
