t=int(input())
for i in range(t):
    n,m,rb,cb,rd,cd=map(int,input().split())
    move=[1,1]
    time=0
    while rd!=rb and cd!=cb:
        if rb==n: move[0]=-1
        if cb==m: move[1]=-1
        rb+=move[0];cb+=move[1]
        time+=1
    print(time)