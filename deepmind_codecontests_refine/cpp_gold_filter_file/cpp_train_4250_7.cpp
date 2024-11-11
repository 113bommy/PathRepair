#include <iostream>
using namespace std;

int main(){
  int a, b, k;
  cin >> a >> b >> k;
  int cnt=0;
  for(int i=100; cnt<k; i--){
    if(a%i==0 && b%i==0)cnt++;
    if(cnt==k)cout << i;
  }
  return 0;
}
