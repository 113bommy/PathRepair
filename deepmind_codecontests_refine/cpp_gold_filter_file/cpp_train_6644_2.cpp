#include<iostream>
using namespace std;
int main(){
  int a,i,sum;
  sum = 0;
  cin >> a;
  for(i=0;i<6;i++){
    sum += a%10;
    a = a/10;
  }
  if(sum == 1)
    sum = 10;
  cout << sum << "\n";
  return 0;
}