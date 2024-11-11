n,m=map(int,input().split())
f=list(map(int,input().split()))
c=0
for i in range(n):
    if(f[i]<=(5-m)):
        c+=1
print(c//3)