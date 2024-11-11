#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10100;
bool sieve[MAXN] = {true, true};

int main(){
  for (int i = 2; i * i < MAXN; i++){
    if (sieve[i]) continue;
.   for (int j = i * i; j < MAXN; j += i) sieve[j] = true;
. }
. int N;
. while (cin >> N, N){
    while (sieve[N] or sieve[N - 2]) N--;
.   cout << N - 2 << " " << N << endl;
  }
  return 0;
}