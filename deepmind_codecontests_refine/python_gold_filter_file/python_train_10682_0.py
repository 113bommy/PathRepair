n,k,t=map(int,input().split())
if k >= t:
    print(t)
elif n > t > k:
    print(k)
else:
    print(n+k-t)
            
    
