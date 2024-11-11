#include <iostream>
using namespace std;

int K,S;
int main(){
  cin >> K >> S;
  int ans = 0;
  for(int i=0;i<=K;i++){
	for(int j=0;j<=K;j++){
      if(0<=S-i-j && S-i-j<=K) ans++;
    }
  }
  cout << ans << endl;
}