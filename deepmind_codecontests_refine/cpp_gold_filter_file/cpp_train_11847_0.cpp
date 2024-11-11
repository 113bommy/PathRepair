#include<iostream>
#include<cmath>
using namespace std;
int main(){
  long long n,a,b;
  cin >> n >> a >> b;
  long long m = min((a+b-1)/2,n+(-a-b+1)/2);
  if((b-a) %2==1)cout << m<<endl;
  else cout << min(m,(b-a)/2)<<endl;
  return 0;
}
