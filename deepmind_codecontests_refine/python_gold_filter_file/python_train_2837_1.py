def solve():
    n,m=map(int,input().split())
    li=[]
    for i in range(n):
        temp=[int(x) for x in input().split()]
        li.append(temp)
    avail=0
    for i in range(n):
        for j in range(m):
            if li[i][j]==1:
                possible=False
                break
        else:
            for j in range(m):
                for k in range(n):
                    if li[k][j]==1:
                        s_possible=False
                        break
                else:
                    li[i][j]=1
                    avail+=1
                    break


    if avail%2==0:
        print('Vivek')
    else:
        print('Ashish')

t=int(input())
for i in range(t):
    solve()