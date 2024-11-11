T = int(input())

for _ in range(T):
    n,x,m = map(int,input().split())
    
    right = x
    left = x
    for i in range(m):
        l,r = map(int,input().split())
        
        if l <= right and right <= r:
            right = min(right,l)
        
        if l <= left and left <= r:
            left = max(left,r)
            
    print(left-right+1)