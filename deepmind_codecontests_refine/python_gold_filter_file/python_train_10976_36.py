n,k=map(int,input().split())
y=list(map(int,input().split()))
c=0
for i in y:
    if 5-i>=k:
        c+=1
print(c//3)
