#include<bits/stdc++>
using namespace std;

int main(){
   int t;
  cin >> t;
  int[t] a;
  for (int i =0 ;i < t; i++){
    cin >> a[i];
  }
  
  sort(a,a+t);
  double rtr = t[0];
  for (int i = 1; i < t; i++){
    rtr = (rtr + t[i])/2;
  }
  
  cout << rtr;
}