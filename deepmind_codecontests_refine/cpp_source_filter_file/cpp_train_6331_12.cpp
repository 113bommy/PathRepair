#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,p;
  cin >> N;
  int sum = 0; M = 10000;
  for (int i = 0; i < N; i++){
    cin >> p;
    sum += p;
    M = max(M,p);
  }
  cout << sum - M / 2;
}