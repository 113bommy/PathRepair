a,b,k=map(int,input().split())
print(max(a-k,0),max(min(b+a-k,b),0))