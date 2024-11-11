t=int(input())

while t:
    t-=1

    q,x,y,z=list(map(int,input().split()))
    
        
    print((abs(q-y))*(abs(x-z))+1)

