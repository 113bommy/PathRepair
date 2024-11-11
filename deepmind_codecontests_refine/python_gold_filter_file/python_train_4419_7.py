n = int(input())

d ={}

for x in range(n):
    
    grp, m = map(int, input().strip().split())
    
    if m not in d:
        d[m] = [[grp,x+1]]
    else:
        d[m].append([grp,x+1])
    
k = int(input())

arr = list(map(int, input().strip().split()))

sums = 0
count = 0
last = -1
lis = []
#print(d)
for e in sorted (d.keys(),reverse = True) : 
    
    for i in d[e]:
        diff = 100000
        f = 0
        #print("i",i)
        for y in range(len(arr)):
            
            if (arr[y] - i[0]) >= 0 and i[0] <= arr[y]:
                if diff > ( arr[y]- i[0]):
                    diff = (arr[y]- i[0])
                    last = y
                    f = 1
                    
        if f == 1:
            lis.append([i[1],last+1])
            arr[last] = -1
            count += 1
            sums += e
            #print("sums",sums,e)
print(count, sums)
for l in lis:
    print(*l)
                    