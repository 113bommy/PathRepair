a,b,k=map(int,input().split())
print(max(a-k,0),max(0,b-max(k-a,0)) )
