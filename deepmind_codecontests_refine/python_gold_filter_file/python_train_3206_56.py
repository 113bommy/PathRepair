a,b,k = map(int,input().split())
print(max(a-k,0),max(min(a+b-k,b),0))