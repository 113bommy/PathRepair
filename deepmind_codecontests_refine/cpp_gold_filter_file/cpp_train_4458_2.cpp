#include<bits/stdc++.h>
using namespace std;
int n,i;
double x,sum;
string u;
int main(){
  cin>>n;
  for(i=0;i<n;i++){
    cin>>x>>u;
    if(u=="BTC")sum+=x*380000.0;
    else sum+=x;
  }
  printf("%f\n",sum);
}
