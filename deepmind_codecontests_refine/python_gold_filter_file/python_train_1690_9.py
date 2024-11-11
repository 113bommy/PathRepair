n=int(input())
l=list(map(int,input().split()))

d={}
for i in range(len(l)):
    x=(i+1)-l[i]

    if x in d:
        d[x]+=l[i]
    else:
        d[x]=l[i]

a=list(d.values())
print(max(a))