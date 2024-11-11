#include<bits/stdc++.h>
using namespace std;

typedef long long int llint;

int main()
{
  int n;
  cin>> n;

  int mn = n;
  
  for(int i = 0; i <= n; i++) {

    int cc = 0; 
    int t = i;  

    while(t > 0) cc += t % 6, t /= 6;
    t = n - i;

    while(t > 0) cc += t % 9, t /= 9;

    mn = min(mn, cc);
    
  }

  cout<< mn <<endl;

  return 0;
}
