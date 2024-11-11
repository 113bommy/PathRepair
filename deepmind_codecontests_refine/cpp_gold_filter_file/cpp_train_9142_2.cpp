#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int a;
  set<int> D={};
  for (int i=0;i<N;i++){
    cin >> a;
    D.insert(a);
  }
  cout << D.size() << endl;
 }
