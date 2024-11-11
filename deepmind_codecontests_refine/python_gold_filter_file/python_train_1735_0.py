n=int(input())
a=[int(x) for x in input().split()]
b=[]
for i in range(n):
    if a[i]>100000000:
        if a[i]*3 not in a and a[i]//2 not in a:
            b.append(a[i])
            a.pop(i)
            break
    else:
        if a[i]*3 not in a and a[i]/2 not in a:
            b.append(a[i])
            a.pop(i)
            break
i=0
while i<len(a):
    if a[i]==b[-1]*2 or a[i]==b[-1]//3:
        b.append(a[i])
        a.pop(i)
        i=0
    else:
        i+=1

b=[str(x) for x in b]
print(' '.join(b))