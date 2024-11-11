#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B,C;
  cin>>A>>B>>C;
  cout<<min(A+B,min(B+C,A+C))<<endl;
}
