#include<iostream>
using namespace std;

int main(){
 int a,b,s;
 char op;
 while(1){
  cin >> a >> op >> b;
  if (op=='?') break;
  
  if (op=='+'){
   s=a+b;
  }
  else if (op=='-'){
   s=a-b;
  }
  else if (op=='*'){
   s=a*b;
  }
  else{
   s=a/b;
  }
  cout << s << endl;
 }
return 0;
}