#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<pair<string,int,int>>book(n);
  for(int i=0;i<n;i++) {
    cin>>get<0>(book[i])>>get<1>(book[i]);
    get<2>(book[i])=i+1;
    get<1>(book[i])*=-1
  }
  sort(book.begin(),book.end());
  for(int i=0;i<n;i++) cout<<get<2>(book[i])<<endl; 
}
