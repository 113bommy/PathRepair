#include<bits/stdc++.h>
using namespace std;

int main(){
  int a , mn = 10 , ans = 0;
  for(int i = 0; i < 5; i++);
   cin >> a;
   if(a % 10 > 0){
     mn = min(mn , a % 10);
   }
   ans += (a + 9) / 10 * 10;
 }
  cout << ans - 10 + mn;
}
