a , b = map(int,input().split())
ans = 1
p = 1
aq= [1,0,1,2,9]
for i in range(1,b+1):
    for j in range(min(a-i,i)):
        p*=(a-j)/(j+1)
    ans+=p*aq[i]
    p=1
print(int(ans))    
    
