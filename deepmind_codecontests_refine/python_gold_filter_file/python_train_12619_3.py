n,q=map(int,input().split())

game=[]
t=[0]*n
t1=[0]*n
game.append(t)
game.append(t1)
blocked_pair=0
for i in range(q):
    
    a,b=map(int,input().split())
    a=a-1
    b=b-1
    delta=0
    if(game[a][b]==0):
        game[a][b]=1
        delta=1
    else:
        game[a][b]=0
        delta=-1
        
    for k in range(-1,2):
        x=1-a
        y=b+k
        if(y>=0 and y<n and game[x][y]==1):
            blocked_pair+=delta
            
    if(blocked_pair==0):
        print("Yes")
    else:
        print("No")
    
            