#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int x,y,s;
  int a,b,maxSum;
  while(true){
    cin >> x >> y >> s;
    if(x == 0 && y == 0 && s == 0) break;
    maxSum = -1;
    for(int i = 1; i <= s; i++){
      for(int j = 1; j <= s; j++){
        if((i*(100+x)/100)+ (j*(100+x)/100) != s) continue;
        else maxSum = max(maxSum,( (i*(100+y)/100) + j*(100+y)/100 ) );
      }
    }
    cout << maxSum << endl;
  }
}

