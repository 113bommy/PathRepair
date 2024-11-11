n,l = map(int, input().strip().split(' '))
lst = list(map(int, input().strip().split(' ')))
j=0
while(j<len(lst)):
    if lst[j]<l:
        del lst[j]
    else:
        j+=1

c=0
if len(lst)==0:
    print(c)
else:
    m=0
    for j1 in range(l,max(lst)+1):
        c=0
        for j in range(len(lst)):
            p1=lst[j]//j1
            c+=p1*j1
        if c>m:
            m=c
    print(m)