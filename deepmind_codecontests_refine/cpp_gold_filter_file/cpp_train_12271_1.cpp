#include <iostream>
using namespace std;

int N,a,b,c;

int main(){
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> a >> b >> c;
    if(a*a+b*b==c*c||a*a+c*c==b*b||b*b+c*c==a*a){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
  }
}