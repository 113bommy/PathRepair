#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a,b;
  cin >> n >> a >> b;
  if(n=a+b||a=b+n||b=a+n){
    cout << "Yes";
  }
  else{
    cout << "No";
  }
}
