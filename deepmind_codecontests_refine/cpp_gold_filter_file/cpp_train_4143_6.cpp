#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll h;
  cin>>h;
  cout<<ll(pow(2,ll(log2(h))+1))-1;
}