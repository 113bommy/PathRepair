import string 
pattern=string.ascii_letters+'0123456789'
t=int(input())
for _ in range(t):
    r,c,k=map(int,input().split())
    grid=[]
    for i in range(r):
        grid+=[list(map(str,input().strip()))]
    l=[]
    countr=0
    #print(grid)
    for strip in grid:
        for element in strip:
            if(element=='R'):
                #print(element)
                countr+=1
    for i in range(k):
        if(countr%k>i):
            l+=[countr//k+1]
        else:
            l+=[countr//k]
    ans=[[0 for i in range(c)] for j in range(r)]
    now=0
    for i in range(r):
        if(i%2==0):
            for j in range(c-1,-1,-1):
                if(grid[i][j]=='R'):
                    if(l[now]==0):
                        now+=1
                    l[now]-=1
                ans[i][j]=pattern[now]
        else:
            for j in range(c):
                if(grid[i][j]=='R'):
                    if(l[now]==0):
                        now+=1
                    l[now]-=1
                ans[i][j]=pattern[now]
            
    #print(countr)
    #print(l)
    for i in ans:
        print(''.join(i))