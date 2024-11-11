n=int(input())
a=list(map(int,input().split()))
aset=list(set(a))
ans=0
al=[0]*200000
for i in a:
    al[i]+=1
for j in aset:
    k=al[j]
    ans+=(k*(k-1))//2
for u in a:
    print(ans-al[u]+1)