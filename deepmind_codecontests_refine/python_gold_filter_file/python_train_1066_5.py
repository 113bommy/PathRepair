#n,t=map(int,input().split())
#arr= list(map(int,input().split()))
tests=int(input())
for _ in range(tests):
    
    n,x,m=map(int,input().split())
    a1=x
    b1=x

    for i in range(m):
        a,b=map(int,input().split())
        if (a1>=a and a1<=b) or ( b1<=b and b1>=a):
            if a<a1:
                a1=a
            if b1<b:
                b1=b
            
    
    print(b1-a1+1)