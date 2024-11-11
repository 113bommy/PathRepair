#include <iostream>
#include<algorithm>
#include<math.h>
#include<set>
#include<vector>
using namespace std;
int main(){
int A,B,C,X,Y;
cin>>A>>B>>C>>X>>Y;
int s,t,u;
s = A*X+B*Y;
t = C*max(X,Y)*2;
if(X>=Y)u= C*Y*2+A*(X-Y);
else u= C*X*2+B*(Y-X);
cout<<min(min(s,t),u)<<endl;
}




