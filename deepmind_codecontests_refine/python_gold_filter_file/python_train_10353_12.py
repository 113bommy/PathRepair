n,k=map(int,input().split())
x=[]
for t in range(n):
    a=list(map(int,input().split()))
    c=-1
    for i in range(1,len(a)):
        if a[i]<k:
            c=0
            break
    if c==0:
        x.append(t+1)
print(len(x))
for  i in sorted(x):
    print(i,end=" ")