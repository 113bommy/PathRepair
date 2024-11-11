#include <bits/stdc++.h>
using namespace std;
int main() {
	string s,a,b; cin>>s;
	a=s.substr(0,2); b=s.substr(2,2);
	cout<<("00"<a&&a<"13"?"00"<b&&b<"13"?"AMBIGUOUS":"MMYY":"00"<b&&b<"13"?"YYMM":"NA");
}