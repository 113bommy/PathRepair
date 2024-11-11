#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

long long int a,b,c,d;

int main(){
  cin >> a >> b >> c >> d;
  for(long long int i = 0;i < a;i++){
    
    for(long long int j = 0;j < b;j++){
      
      cout << long long int (((i < d) + (j < c)) % 2);
    }
    
    cout << endl;
  }
}
