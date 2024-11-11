#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  double k=0;
  
  for(int i=0;i<n;i++){
    double x;  string y;
    cin >> x >> y;
    if(y=='BTC')
      x*=380000;
    k+=x;
  }
  printf("%.10f",k);
}