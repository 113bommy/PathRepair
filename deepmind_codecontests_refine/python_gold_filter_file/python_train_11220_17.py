n=int(input())
a=[int(i) for i in input().split()]
b=1
a.sort()
for i in a:
    b=b*i
    
    if b>10**18:
        b=-1
        break
    
print(b)