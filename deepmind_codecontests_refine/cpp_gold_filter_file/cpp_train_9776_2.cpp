#include <iostream>
using namespace std;

int main(){
  int k;
  while(cin >> k,k){
    int ans = 0;
    for(int i=0;i<k*(k-1)/2;i++){
      int tmp;
      cin >> tmp;
      ans += tmp;
    }
    cout << ans/(k-1) << endl;
  }
}