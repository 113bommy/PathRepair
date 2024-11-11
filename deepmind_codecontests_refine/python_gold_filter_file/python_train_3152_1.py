import sys
for _ in range(int(input())):
    a,b,x,y,n=map(int,input().split())
    ans1=(a-min(n,a-x))*(b-min(b-y,n-min(n,a-x)))
    ans2=(b-min(n,b-y))*(a-min(a-x,n-min(n,b-y)))
    print(min(ans1,ans2))
        
    
        
        
