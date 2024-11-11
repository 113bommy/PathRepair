n,k=map(int,input().split())
a=list(map(int,input().split()))
t=a[0]
c=0
i=1

while i<len(a):
    if t>a[i]:
        a.append(a[i])
        c+=1
    else:
        c=1
        a.append(t)
        t=a[i]
    if c>=k:
        print(t)
        break
    if i>2*(n-1):
        print(max(a))
        break
    i+=1
