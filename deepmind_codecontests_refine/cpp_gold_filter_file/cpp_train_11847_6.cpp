#include<iostream>

using namespace std;

int main(){
  long long n,a,b;
  cin>>n>>a>>b;
  if((b-a)%2==0)
    cout<<(b-a)/2;
  else
  	cout<<min(a-1, n-b) + 1 + (b-a-1)/2;
  return 0;
}
