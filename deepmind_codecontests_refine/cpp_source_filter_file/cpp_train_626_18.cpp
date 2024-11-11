#include<iostream>

using namespace std;

int main(){
  int a,b,c,cnt=0;
  cin >> a >> b > >c;
  for(;a<=b;a++){
    if(a%c==0) cnt++;
  }
  cout << cnt << endl;
}
