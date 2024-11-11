#include <iostream>
using namespace std;
int main()
{
int a, b , c, d;
cin>>a>>b>>c>>d;

int sum = a>b ? b:a;
sum+= (c>d?d:c);
cout<<sum;
return 0;
}