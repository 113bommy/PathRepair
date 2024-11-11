n=int(input())
a=list(map(int,input().split()))
l=[n,a[-1]]
p=a[-1]
while a[p-2]!=1:
    l.append(a[p-2])
    p=a[p-2]
if l[-1]!=1:
    l.append(1)
l.reverse()
print(*l)



