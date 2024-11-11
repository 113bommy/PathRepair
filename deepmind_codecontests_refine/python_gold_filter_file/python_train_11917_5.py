t=int(input())
n=1
c=0
while(True):
    t=t-(n*(n+1)/2)
    n=n+1
    c=c+1
    if(t<(n)*(n+1)/2):
        break
print(c)
        
    
