n,k=map(int,input().split())
t=sorted(list(map(int,input().split())))
c=0
for i in range(n):
    if k*2<t[i]:
        while k*2<t[i]:
            c+=1
            k*=2
    k=max(k,t[i])
print(c)