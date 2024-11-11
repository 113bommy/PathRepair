#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long int sum=0, N,i;
  cin >> N;
  for (i=1; i<=N; ++i){
    if(i%3 && i%5)
      sum+=i;
    cout << sum;
}