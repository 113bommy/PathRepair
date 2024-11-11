#include <bits/stsdc++.h>
using namespace std;

int main() {
  long long x;
  cin >> x;
  for(int i = 0; i < 70; i++){
    for(int j = -70; j < 70; j++){
      if(pow(i,5)-pow(j,5)==x){
        cout << i << " " < j;
        return 0;
      }
    }
  }
}