n=int(input())
ans=[[0 for i in range(n)] for j in range(n)]
# for i in ans:
#     print(i)
start=0
od=1
do=n
for i in range(n//2,n):
    for j in range(start, start+do):
        ans[i][j]=od
        od+=2
    start+=1
    do-=2
start=n//2
do=1
for i in range(0,n//2):
    for j in range(start, start+do):
        ans[i][j]=od
        od+=2
    start-=1
    do+=2
ev=2
for i in ans:
    for j in i:
        if j:
            print(j,end=' ')
        else:
            print(ev,end=' ')
            ev+=2
    print('')
