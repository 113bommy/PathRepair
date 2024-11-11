#include <iostream>
using namespace std;
int main(){
int n, x , y, sum=0;
cin >> n >> x;
for(int I=1; i<=n; i++){
cin >> y;
if(y>=x){
sum ++;
}
}
cout << sum << endl;
return 0;
}