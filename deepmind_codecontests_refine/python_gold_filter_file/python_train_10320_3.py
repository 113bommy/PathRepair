n=int(input())
a=[[] for i in range(n+1)]
for i in range(n):
    a[i+1]=list(map(int,input().split()))
ans=[1]
i=1
while len(ans)<n:
    if a[i][1] in a[a[i][0]] and a[i][0]!=1:
        ans.append(a[i][0])
        i=a[i][0]
    else:
        ans.append(a[i][1])
        i=a[i][1]
print(*ans)

    
