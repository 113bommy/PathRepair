#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,i,j,d=0;
  cin >> a;
  int b[a];
  for(i=0;i<n;i++){
    cin >> b[i];
  }
  for(i=0;i<a;i++){
    for(j=0;j<a;j++){
      d=d+b[i]*b[j];
    }
  }
  cout << d << endl;
}
