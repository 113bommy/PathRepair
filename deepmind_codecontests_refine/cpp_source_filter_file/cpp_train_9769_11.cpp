#include<bits/stdc++.h>
using namespace std;
int main(){
  int a;
  
  cin>>a;
  if(a[0]==a[1]&&a[1]==a[2]||a[3]==a[1]&&a[1]==a[2])
    cout << "Yes" <<endl;
  else cout << "No" <<endl;
}