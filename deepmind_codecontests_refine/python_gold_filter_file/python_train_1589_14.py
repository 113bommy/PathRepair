t=int(input())
for _ in range(t):
 x,y,n=map(int,input().split())
 if n%x==y:
    print(n)
 else:
    a=n%x
    if a<y:
        b=y-a
        print(n-(x-b))
    else:
        print(n-(a-y))
    
    
 
 
