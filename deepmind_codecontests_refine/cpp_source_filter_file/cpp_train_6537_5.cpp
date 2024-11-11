#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,s=0; cin >>n;
  vector<int>a(n-1);
  for(int i=0; i<n-1; i++){cin >>a[i];}
  for(int i=0; i<n-2; i++){s+=min(a[i],a[i+1]);}
  s+=a[0]+s[n-2];
  cout <<s;
return 0;
}