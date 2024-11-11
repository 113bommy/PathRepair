n=int(input())
v=['a','e','i','o','u','y']
l=[int(i) for i in input().split()]
for i in range(0,n):
    s=[j for j in input().split()]
    count=0
    for j in s:
        for k in j:
            if(k in v):
                count+=1
    if(count!=l[i]):
        print('NO')
        exit()
print('YES')
        
