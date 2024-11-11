n=int(input())
l=[0]*100
for k in range(n):
    a,b=map(int,input().split())
    for i in range(a,b):
        l[i]=int(k==0)
print(sum(l))