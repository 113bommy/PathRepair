t=int(input())
for _  in range(t):
    l=list(map(int,input().split()))
    a,b,c=l[0],l[1],l[2]
    if(c<=a):
        print(-1,end=' ')
        print(b)
    elif(c/b>=a):
        print(1,end=' ')
        print(-1)
    else:
        print(1,end=' ')
        print(b)
    
