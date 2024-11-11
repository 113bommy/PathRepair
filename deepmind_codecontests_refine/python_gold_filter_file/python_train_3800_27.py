n,x=[int(x) for x in input().split()]
count=0
for i in range(1,min(n,x)+1):
    if x/i==int(x/i) and (x/i)<=n:
        count+=1
print(count)
        
