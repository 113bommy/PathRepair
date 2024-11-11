n=int(input())
a=list(map(int,input().split()))
if a==sorted(a):
    print(0)
    exit()
ans=0
ans2=[[] for i in range(n)]
for i in range(n):
    cur=min(a[i:])
    yep=a[i:].index(cur)+i
    ans+=1
    ans2[i].append(i)
    ans2[i].append(yep)
    a[i],a[yep]=a[yep],a[i]
    if a==sorted(a):
        break
print(ans)
for x in ans2:
    if len(x)==0:
        break
    else:
        print(*x)