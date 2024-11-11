n,h = map(int,input().split())
c = 0
b = 0 

l =  list(map(int,input().split()))
for i in l:
    if i <= h:
        c += 1 
    elif i > h:
        b += 2
print(b+c)    
