#include <bits/stdc++.h>
using namespace std;

string s;

int main(){
cin >> s;
sort(s.begin(), s.end());
cout << (s == "abc" ? "Yes\n" : "No\n");
}