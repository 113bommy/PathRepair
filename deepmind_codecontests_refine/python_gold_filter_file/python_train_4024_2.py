a = int(input())
c = input().split()
for i in range(len(c)):
    c[i]=int(c[i])
d=1-c[0]
if d in c:
    x=c.index(d)
else:
    print('YES')
    exit(0)
k=0    
for l in c:
    if l==(d+(k//x)%2)%2:
        print('NO')
        exit(0)
    k+=1
if k%x!=0:    
    print('NO')
    exit(0)
print('YES')    
