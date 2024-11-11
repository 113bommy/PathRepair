n,m=map(int,input().split())
sw=[]
la=[0 for i in range(m)]
for i in range(n):
    ap=[int(i) for i in input()]
    sw.append(ap)
    for k in range(m):
        if ap[k]==1:
            la[k]+=1
for i in range(n):
    a=sw[i]
    for k in range(m):
        if a[k]==1:
            if la[k]==1:
                break
    else:
        print('YES')
        quit()
print('NO')
    
    
