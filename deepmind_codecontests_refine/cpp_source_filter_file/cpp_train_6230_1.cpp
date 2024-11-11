#includ<iostream>
main(){
  std::string s;
  std::cin>>s;
  int n=s.size();
  for(int i=0;i<n-1;++i){
    if(s[i]=='A'&&s[i+1]=='C'){
      puts("Yes");
      return 0;
    }
  }
  puts("No");
}