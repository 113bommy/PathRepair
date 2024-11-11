a,b,k=map(int,input().split())
c=[i for i in range(100,0,-1) if a%i==0 and b%i==0]
print(c[k-1])