#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  char abc[50];
  cin >> a >> b >> abc;
  abc[b-1] += 32;
  cout << abc << endl;
}