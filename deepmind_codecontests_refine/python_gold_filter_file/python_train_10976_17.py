n,k=map(int,input().split())
l=list(map(int,input().split()))
c=0
for i in range(n):
    if k+l[i]<=5:
        c+=1
print(c//3)