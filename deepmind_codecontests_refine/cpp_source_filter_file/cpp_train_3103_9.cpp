#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int a[n];
  int d=0,e=0,f=99999999;
  for(int i=0;i<n;i++){
    cin >> a[i];
    d+=a[i];
  }
  for(int i=0;i<n;i++){
    e+=a[i];
    d-=a[i];
    if(f>abs(d-e))f=abs(d,e);
  }
  cout << f;
}
