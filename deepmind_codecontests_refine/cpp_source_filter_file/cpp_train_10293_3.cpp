#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int a[n];
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  int q,w=1000000000;
  for(int i=-100;i<101;i++){
    q=0;
    for(j=0;j<n;j++){
      q+=(a[j]-i)*(a[j]-i);
    }
    w=min(w,q);
  }
  cout << w;
}
