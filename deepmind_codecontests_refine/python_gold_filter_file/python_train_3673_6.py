T=int(input())

for _ in range(T):
    N=int(input())
    S=input()
    
    snake=[False]*N
    clock=0
    anticlock=0

    for i in range(N):
        if S[i]=='-':
            snake[i]=True
            snake[(i+1)%N]=True
        elif S[i]=='>':
            clock+=1
        else:
            anticlock+=1
        
    if clock==0 or anticlock==0:
        ans=N
    else:
        ans=sum(snake)

    print(ans)