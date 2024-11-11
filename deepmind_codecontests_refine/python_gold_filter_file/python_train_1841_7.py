k=int(input())
b=set()
e=[]
for i in range(k):
    n=int(input())
    a=list(map(int,input().split()))
    s=sum(a)
    c=[]
    d=[s]
    for j in range(n):
        if s-a[j] in b:
            print('YES')
            print(i+1,j+1)
            for k in range(len(e)):
                for p in range(1,len(e[k])):
                    if e[k][0]-e[k][p]==s-a[j]:
                        print(k+1,p)
                        exit()
        else:
            c.append(s-a[j])
        d.append(a[j])
    for j in c:
        b.add(j)
    e.append(d)
print('NO')
