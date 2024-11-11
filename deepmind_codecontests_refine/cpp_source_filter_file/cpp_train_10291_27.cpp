#include<bits/stdc++.h>
using namespace std;

int main(){
  int a[] = {1,3,1,2,1,2,1,1,2,1,2,1};
  int x,y;
  cin >>x>>y;
  
  string ans;
  a[x-1]==a[y-1] ? ans="Yes" : ans="No"
  cout <<ans<< endl;
}
