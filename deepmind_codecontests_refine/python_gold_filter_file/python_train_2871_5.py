a = int(input())
l=[int(x) for x in input().split()]
count=0
b =l.copy()

for i in range(0,a//2,2):
    l[i],l[-1-i]=l[-1-i],l[i]
    
print(*l)