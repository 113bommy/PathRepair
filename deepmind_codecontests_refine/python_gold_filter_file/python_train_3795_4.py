n=int(input())
s1=n//2
d1=1
s2=1
d2=n-2
for i in range(1,n+1):
    if i<n//2+1:
        print("*"*s1+"D"*d1+"*"*s1)
        s1=s1-1
        d1=d1+2
    elif i==n//2+1:
        print("D"*n)
    elif i>n//2+1:
        print("*"*s2+"D"*d2+"*"*s2)
        s2=s2+1
        d2=d2-2
        
        
    
    