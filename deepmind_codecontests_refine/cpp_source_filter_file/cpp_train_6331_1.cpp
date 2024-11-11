#include <iostream>
#include <limits.h>
using namespace std;
int main(){
int D;
cin >> D;
int max = 0;
int sum=0;
for (int i=0;i<N;i++)
{
int p;
cin>>p;
if(p>max)
max=p;
sum+=p;
}
cout << sum - (int)max /2 <<endl;
}