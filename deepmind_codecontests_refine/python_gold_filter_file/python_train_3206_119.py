a,b,k=map(int,input().split())
print(max(a-k,0),max(min(b,a+b-k),0))