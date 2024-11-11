n,k = map(int, input().split())

numbers=list(map(int,input().split()))

counts=[i for i in range(1,n+1)]

colors=[0]*n

indexednumbers=[list(a) for a in zip(numbers,counts,colors)]

indexednumbers.sort()


unique=1
c=1
indexednumbers[0][2]=c
bad=False

for j in range(1,n):
    indexednumbers[j][2]=(c%k)+1
    c+=1
    if not indexednumbers[j][0]==indexednumbers[j-1][0]:
        unique=1
    else:
        unique+=1
        if unique>k:
            bad=True
if bad:
    print('NO')
    
else:
    print('YES')
    indexednumbers.sort(key=lambda x:x[1])
    sequence=[]
    for i in range(n):
        sequence.append(indexednumbers[i][2])
        
    print(*sequence)    