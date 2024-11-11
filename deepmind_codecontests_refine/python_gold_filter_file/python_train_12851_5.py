n,m=map(int,input().split(" "))
L=[(lambda x: x%m==0 and x//m or x//m+1 )(k) for k in map(int,input().split(" "))]
print(n-L[::-1].index(max(L[::-1])))