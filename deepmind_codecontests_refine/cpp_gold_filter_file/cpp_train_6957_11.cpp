#include<iostream>
#include<string>
using namespace std;
int main(){
  string  a,b;
  cin>>a>>b;
  int x=stoi(a+b);
  for(int i=0;i<=1000;i++){
    if(x==i*i){
      puts("Yes");
      return 0;
    }
  }
    puts("No");
}
  