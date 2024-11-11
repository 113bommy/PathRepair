n,m=map(int, input().split())
List=list(map(int, input().split()))
d=[0]*n*9+[-1]*n*9
#print(d)
for i in range(1, n+1):
    d[i]=max(d[i-int("0255456376"[a])]*10+a for a in List)
print(d[n])
