#include<bits/stdc++.h>
using namespace std;

int main (){

string n;
int a=0;

cin >> n;

for(int i = 0; i < n.size(); i++) {
  if (n[i]=='2'){
  a++;
  }
}
cout << a <<endl;
}