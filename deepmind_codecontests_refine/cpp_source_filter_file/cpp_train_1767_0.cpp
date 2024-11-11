include<iostream>
#include<map>

int main(){
  std::map<long long,long long> counter;
  std::string line;
  int tmp = 0;
  getline(std::cin,line);
  for(int i=0;i<(int)line.size();i++){
    tmp += ((line[i]=='(')?+1:-1);
    if(tmp)counter[tmp]++;
  }
  long long ans = 0;
  for(std::pair<long long,long long> iter : counter)ans += (iter.second*(iter.second-1))/2;
  std::cout << ans << std::endl;
  return 0;
}