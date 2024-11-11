#include "bits:stdc++.h"
using namespace std;
int main()
{
string s;
cin >> s;
if(s.length() == 2)cout << s;
else {
reverse(s.begin(), s.end())
cout << s;
}
}