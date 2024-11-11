n,k=map(int,input().split())
y=list(map(int,input().split()))
m=6-k
a=[]
for i in y:
    if i<m:
        a.append(i)
print(len(a)//3)
