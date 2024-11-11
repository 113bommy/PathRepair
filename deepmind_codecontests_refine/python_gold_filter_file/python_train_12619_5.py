n,q= tuple(map(int, input().split()))
blockedCount=0

maze=list()
maze.append([False]*n)
maze.append([False]*n)

for i in range(q):
    r,c=tuple(map(int, input().split()))
    maze[r-1][c-1]^=True
    if maze[r-1][c-1]==True:    #ground turned to lava
        if c-2>=0 and maze[1-(r-1)][c-1-1]==True:  blockedCount+=1
        if maze[1-(r-1)][c-1]==True:  blockedCount+=1
        if c<n and maze[1-(r-1)][c-1+1]==True:  blockedCount+=1

    if maze[r-1][c-1]==False:    #ground turned to lava
        if c-2>=0 and maze[1-(r-1)][c-1-1]==True:  blockedCount-=1
        if maze[1-(r-1)][c-1]==True:  blockedCount-=1
        if c<n and maze[1-(r-1)][c-1+1]==True:  blockedCount-=1

    #print(blockedCount)
    if blockedCount==0: print('YES')
    else: print('NO')
    


