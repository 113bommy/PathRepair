#include<iostream>
#include<string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdint>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main(){

int q;
cin >> q;

for(int i = 0; i<q; i++){

ll a,b;
cin >> a >> b;

ll c =   sqrt(a*b);         // cの2乗はa*bよりも小さい,最大の値をとる

if(a == b)                    cout << 2*(c-1) << endl; 
else if((a*b) == (c*c) )  cout << 2*(c-1)-1 << endl; 
else{ 
if(c*(c+1) < a*b)         cout << 2*c -1 << endl;
else                           cout << 2*c -2 << endl;
   }
 }
return 0;