#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long int N,s;
  s=0;
  cin >> N;
  vector<int> A(100001);
  for(int i=0;i<N;i++){
    int x;
    cin >> x;
    s += x;
    A.at(x)++;
  }
  int Q;
  cin >> Q;
  for(int j=0;j<Q;j++){
    long int B,C;
    cin >> B >> C;
    A.at(C) += A.at(B);
    s += (C-B)*A.at(B);
    cout << s << endl;
    A.at(B)=0;
  }
}
