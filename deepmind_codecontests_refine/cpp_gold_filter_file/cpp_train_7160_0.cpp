#include<bits/stdc++.h>
using namespace std;
bool is_palindrome(string s)
{
    string t(s.rbegin(),s.rend());
    return s==t;
}
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    if(is_palindrome(s)&&is_palindrome(s.substr(0,(n-1)/2))&&is_palindrome(s.substr((n+1)/2)))
    cout<<"Yes";
    else
    cout<<"No";
}