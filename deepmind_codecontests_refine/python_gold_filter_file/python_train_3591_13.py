n,m=map(int,input().split())
if m>n-m: print(max(m-1,1))
else: print(m+1)