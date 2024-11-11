n,k=map(int,input().split())
l=list(map(int,input().split()))
c=0
for i in l:
    if i<=5-k:
        c+=1
print(c//3)