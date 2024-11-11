#include <iostream>
#include <algorithm>
#include <cassert>
#include <cctype>
#include <complex>
#include <cstdio>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int n,m;
__int64 s;

int main(){
	cin>>n;
	for(int i=0;i<n;i++){cin>>m;s+=m;}
	cout<<s/n<<endl;
}