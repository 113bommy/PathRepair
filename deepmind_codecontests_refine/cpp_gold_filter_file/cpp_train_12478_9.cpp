#include <iostream>
#include<vector>
using namespace std;
int main(void){
   int n;
   cin >> n;
   string s,t;
   cin >> s;
   cin >> t;
   int res = 0;
   for(int i = 0;i <= n;i++){
         if(s.substr(n - i,i) == t.substr(0,i)) res =i;
   }
   cout << 2 * n - res << endl;
}
