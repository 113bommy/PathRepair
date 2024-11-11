#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long sum=0, N;
  cin >> N;
  for (i=1; i<=N; ++i){
    if(i%3 && i%5)
      sum+=i;
    cout << sum;
}