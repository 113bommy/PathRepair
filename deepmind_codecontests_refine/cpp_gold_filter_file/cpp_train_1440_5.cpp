#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,x;
  cin >> n >> x;
  int a[n],b=1000;
  for(int i=0;i<n;i++){
    cin >> a[i];
    x-=a[i];
    b=min(b,a[i]);
  }
  n+=x/b;
  cout << n;
}
