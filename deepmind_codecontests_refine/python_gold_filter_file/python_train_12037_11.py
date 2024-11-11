
n,x = map(int,input().split())

l = set(list(map(int,input().split())))
count = 0
c = max(max(l)+1,x+1)
if x in l:
    count+=1
    l.remove(x)

for i in range(0,x+1):
    if i == x:
        continue
    else:
        if i not in l:
            count+=1

print(count)


