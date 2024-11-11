#include <iostream>
#include <string>
#include <algorithm.h>
using namespace std;

int main()
{
string a;
cin>>a;
reverse(a.begin(),a.end());
cout<<a<<endl;
return 0;
}