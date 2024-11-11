#include<iostream>
using namespace std;
int main()
{
int j,t,r;
cin >> j >> t >> r;
if(r==1 || j==1 && t ==1)
{
cout << "Open" << endl;
}
else cout << "Close" << endl;
return 0;
}