#include <iostream>

using namespace std;

int main()
{ int a,b,c,d,e,k;
cin>>a>>b>>c>>d>>e>>k;
if (e-a>k||e-b>k||e-c>k||e-d>k)
{
    cout << ":(";
}
else
    cout << "Yay!";
}
