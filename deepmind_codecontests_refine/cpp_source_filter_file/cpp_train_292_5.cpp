#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
  long long N,a,counter=0;
  cin>>N;
  long long a[100000];
  for (long long i=1; i<=N; i++){
  cin>>a[i];}
  for (long long i=1; i<=N; i++){
  if(a[i]==i){
  counter++;
  a[i+1]=i;}}
  cout<<counter<<endl;}
  
