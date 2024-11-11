#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N,B,A;
  cin>>N>>A>>B;
  cout<<A*(N/(A+B))+min(N%(A+B),A);
 
}
