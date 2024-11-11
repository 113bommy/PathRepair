#include <bits/stdc++.h>

using namespace std;
int main(){
  int n;
   cin >>n;
  
  vector<long> x(n),y(n);
  for(int i=0;i<n;i++) {
    cin >> x[i];
    y[i]=x[i];
  }
  sort(y.begin(),y.end(),greater<long>());
  
 
  for(int i=0;i<n;i++){
  if((x[i]>y[n/2-1])||(x[i]==y[n/2-1]&&y[n/2-1]>y[n/2])) cout << y[n/2] << endl;
  else cout << y[n/2-1] << endl;
  }
    
  