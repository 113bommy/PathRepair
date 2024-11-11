#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,sum=0,sqsum=0;
  cin >> n;
  int a[n];
  for(int i=0;i<n;i++){
    cin >> a[i];
    sum+=a[i];
    sqsum+=a[i]*a[i];
  }
  cout << sum*sum-suqsum << endl;
}