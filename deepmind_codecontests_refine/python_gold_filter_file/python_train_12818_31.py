n,x,y=map(int,input().split())
l=list(map(int,input().split()))
cur=0
if x>y:
    print(len(l))
elif x<=y:
    for i in range(n):
        if l[i]<=x:
            cur+=1
    print((cur+1)//2)
    
        
