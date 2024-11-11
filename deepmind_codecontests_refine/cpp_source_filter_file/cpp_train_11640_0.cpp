#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int a[n];
  for(int i=0;i<n;i++)cin >> a[i];
  for(int i=n-2;i>=0;i--){
    if(a[i+1]+1<a[i]){
      cout << "No";
      return 0;
    }
    if(a[i+1]+1=a[i])a[i]--;
  }
  cout << "Yes";
}
