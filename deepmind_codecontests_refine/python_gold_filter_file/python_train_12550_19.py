def screen(n,c,a):
    r=0
    for i in range(1,n):
        if a[i]-a[i-1]<=c:
            r+=1
        else:
            r=0
    print(r+1)
    
    

n,c=list(map(int,input().split()))    
a=list(map(int,input().split()))
screen(n,c,a)
    