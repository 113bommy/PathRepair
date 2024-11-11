#include <iostream>
using namespace std;
int main(){
  int n;cin>>n;
  long long ret = 1;
  for(int i = 1; n >= i; i++){
	ret = (ret * i)%1000000007;
  }
  cout << ret << endl;
}