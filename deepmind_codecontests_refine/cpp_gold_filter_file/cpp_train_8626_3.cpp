#include <iostream>
#define STA 50000
using namespace std;

int prime[50001];

int main(){
  int n;
  int cnt;
  for(int i=2;i<=STA/2;i++){
    for(int j=2;i*j<=STA;j++){
      prime[i*j] = 1;
    }
  }
  while(1){
    cnt = 0;
    cin >> n;
    if(n == 0) break;
    for(int i=2;i<=n/2;i++){
	if(prime[i] == 0 && prime[n-i] == 0) cnt++;
    }
    cout << cnt << endl;
  }
}