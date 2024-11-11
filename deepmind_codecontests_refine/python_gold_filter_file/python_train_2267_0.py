x,n=map(int,input().split())
p=list(map(int,input().split()))
a=[1000]*102
for i in range(102):
    if i not in p:
        a[i]=abs(x-i)
print(a.index(min(a)))