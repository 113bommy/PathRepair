#include<stdio.h>
using namespace std;
int main()
{
string s;
cin >> s;
if(s.at(0)==s.at(2)) cout << "Yes";
else cout << "No";
return 0;}