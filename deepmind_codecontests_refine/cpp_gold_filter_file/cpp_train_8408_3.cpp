#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long x;
  cin >> x;
  for(int i = 0; i < 200; i++){
    for(int j = -100; j < 200; j++){
      if(pow(i,5)-pow(j,5)==x){
        cout << i << " " << j;
        return 0;
      }
    }
  }
}