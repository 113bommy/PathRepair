t=int(input())
for _ in range(t):
    
    n,m,k=map(int,input().split())
    while(k>=3):
        k=k%3
    if k==0:
        print(n)
    elif k==1:
        print(m)
    elif k==2:
        print(n^m)
    
        
        