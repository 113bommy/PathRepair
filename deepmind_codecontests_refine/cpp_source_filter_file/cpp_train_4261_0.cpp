include <iostream>
#define MAX 1000000

using namespace std;

bool prime[MAX];

void isPrime(void){

  fill(prime, prime + MAX, true);
  prime[0] = prime[1] = false;
  for(int i = 0 ; i*i < MAX ; i++){
    if(prime[i]){
      for(int j = i*i ; j < MAX ; j += i){
	prime[j] = false;
      }
    }
  }
}

int main(void){

  isPrime();

  int n;
  while(cin >> n, n){
    int cnt = 0;
    for(int i = 2 ; n - i >= i ; i++){
      if(prime[i] && prime[n - i]) cnt++;
    }
    cout << cnt << endl;
  }
  return 0;
}