n,k=map(int,input().split())
y=list(map(int,input().split()))
count=0
b=0
for i in y:
    if i<=5-k:
        b+=1
    if b==3:
        count+=1
        b=0
print(count)