#include<bits/stdc++.h>
using namespace std;

int main (){

string s;
int r=0;

cin >> s;

for(int i=0;i<s.size();i++){
if(s[i] =='1')r++;
}

cout << r <<endl;
}
