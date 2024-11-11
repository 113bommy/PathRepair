#include <iostream>
#include <string>
using namespace std;

int main(){
 int sum;
 string x;

 while(1){
  cin >> x;
  if(x=="0")break;
  sum=0;
  for(int i=0;i<x.size();i++){
   sum+=x[i]-'0';
  }
  cout << sum << endl;
 }
 return 0;
}