#include <cstdio>
#include<iostream>
#include<algorithm>

using namespace std ;
int main(){
int n ;
int a[15];
int x[15][15];
bool y[15][15];
int max=0;
cin >> n ;
for(int i=0;i<n;i++){
 cin >> a[i];
 for(int j=0;j<a[i];j++){
  cin>>x[i][j]>>y[i][j];
  }
 }
for(int bit=0;bit<(1<<n);bit++){
bool flag=1;
 for(int i=0;i<n;i++){
  for(int j=0;j<a[i];j++){
if(bit&(1<<i) && y[i][j]!= (bool)(bit&(1<<x[i][j]-1)))flag=0;
  }
 }
if(flag)max= max(__builtin_popcount(bit),max);
}
cout << max << endl;
return 0;
}