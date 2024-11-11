#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  long long int ar[n],s=0;
 for(int i=0;i<n;i++)
   cin>>ar[i],s=s^ar[i];
  for(int i=0;i<n;i++)
    cout<<s^ar[i]<<" ";
  cout<<"\n";
 return 0;
}