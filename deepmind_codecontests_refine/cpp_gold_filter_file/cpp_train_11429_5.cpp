#include<bits/stdc++.h>
using namespace std;
int main(){
  char S[11], T[12] ,*p;
  cin >> S >> T;
  for(p=S;*p==*(T+(p-S));p++);
  cout << ((*p)?"No":"Yes") << endl;
}