#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  char abc[];
  cin >> a >> b >> abc;
  abc[b-1] += 32;
  cout << abc << endl;
}