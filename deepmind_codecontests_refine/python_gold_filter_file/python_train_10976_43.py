n,k=map(int,input().split())
a=list(map(int,input().split()))
c=0
teams=0
for i in range(n):
    if abs(a[i]+k)<=5:
        teams+=1
    if teams==3:
        c+=1
        teams=0
print(c)
        