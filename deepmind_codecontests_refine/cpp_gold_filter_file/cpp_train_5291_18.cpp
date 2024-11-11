#include<iostream>
using namespace std;
 
int main(){
  int N;
  cin >> N;
  if(N == 1) cout << "Hello World";
  else {
    int a,b;
    cin >> a >> b;
    cout << a+b;
  }
}