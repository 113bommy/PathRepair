t = int(input())

for i in range(t):
    n,m,x,y = map(int, input().split())
    row=['']*(n)
    sum = 0
    for i in range(n):
        row[i]=input()
    if 2*x<y: #1x1 is cheaper than 1x2 
        for i in range(n):
            for j in range(m):
                if row[i][j]=='.':
                    sum += x
    else:
        for r in row:
            k = 0
            while(k<m):
                if m-k>=2:
                    if r[k]=='.' and r[k+1]=='.':
                        k +=1
                        sum += y
                    elif r[k]=='.':
                        sum +=x
                else:
                    if r[k]=='.':
                        sum +=x
                k +=1
    print(sum)
