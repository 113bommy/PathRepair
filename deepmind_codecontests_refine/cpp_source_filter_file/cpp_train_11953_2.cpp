#include<iostream>
#include<algorithm>
#include<set>

int main(){
  int n;
  std::cin >> n;
  std::string a,b,c;
  std::cin >> a >> b >> c;
  int cnt = 0;
  for(int i = 0; i < n; i++){
    std::set<char> st;
    st.insert(a[i]);
    st.insert(b[i]);
    st.insert(c[i]);
    cnt += st.size() - 1:
  }
  std::cout << cnt << std::endl;
}