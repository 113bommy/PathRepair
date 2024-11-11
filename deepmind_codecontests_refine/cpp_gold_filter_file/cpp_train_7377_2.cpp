#include<iostream>
#include<algorithm>
#define N 101
using namespace std;

int main(){

  int i, m, a[N] = {};
  while(cin >> i)
    a[i]++;

  for(int j = 1; j < N; j++) 
    m = max(m,a[j]);

  for(int k = 1; k < N; k++)
    if(a[k] == m) 
      cout << k << "\n";
  
}