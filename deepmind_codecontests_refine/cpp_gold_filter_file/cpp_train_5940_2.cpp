#include <iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int main() {
  while(1){
    int n;
    cin>>n;
    if(n==0)break;
    int s[n];
    double sum=0;
    for(int i=0;i<n;i++){
      cin>>s[i];
      sum+=s[i];
    }
    double a=0;
    sum/=n;
    for(int i=0;i<n;i++)a+=pow(s[i]-sum,2)/n;
    cout<<setprecision(10)<<sqrt(a)<<endl;
  }
  return 0;
}