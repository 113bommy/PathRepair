#include<bits/stdc++.h>
using namespace std;
int main(){
  long long n,k;
  cin>>n>>k;
  int c=0;
  while(n){
    n/=k;
    c++;
  }
  cout<c;
}
    