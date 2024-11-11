n,m=map(int,input().split())
if m//2<n:print("NO")
else:print("YES","1 "*(n-1)+str(m-n+1),m//2,sep="\n")