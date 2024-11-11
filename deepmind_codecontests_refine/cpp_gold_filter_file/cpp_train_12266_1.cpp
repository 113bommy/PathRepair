#include<iostream>
using namespace std;
long long gcd(long long a,long long b){
if(b==0) return a;
else return gcd(b,a%b);
}

int main(){
int n;
  cin>>n;
  long long X;
  cin>>X;
  long long res=0;
  for(int i=0;i<n;i++){
    long long x;
    cin>>x;
    res=gcd(res,abs(x-X));
  }
  cout<<res<<endl;
  return 0;
}
