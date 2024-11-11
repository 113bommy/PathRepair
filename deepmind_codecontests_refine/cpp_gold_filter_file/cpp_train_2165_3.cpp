#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int a[n];
  int k=1,l=0;
  for(int i=0;i<n;i++){
    cin >> a[i];
    if(a[i]==k){
      l++;
      k++;
    }
  }
  if(k==1){
    cout << -1;
    return 0;
  }
  cout << n-k+1;
}
