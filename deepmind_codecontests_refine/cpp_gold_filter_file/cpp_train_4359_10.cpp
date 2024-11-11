#include <bits/stdc++.h>
using namespace std;

int a;
set<int> s;
int main(){
     for(int i = 0; i < 3; i++){ cin >> a; s.insert(a); }
     cout << s.size();
}
