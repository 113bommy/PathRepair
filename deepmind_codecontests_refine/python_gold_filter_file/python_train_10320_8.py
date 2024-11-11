numKids = int(input())
p = {}
for i in range(1,numKids+1,1):
   a1, a2 = map(int,input().split())
   p[i] = (a1,a2)

kidOrder = [1]
i=1

while len(kidOrder) < numKids:
    (a1,a2) = p[i]
    if a2 in p[a1] and a1 != 1:
        kidOrder.append(a1)
        i=a1
    else:
        kidOrder.append(a2)
        i=a2
    
print(*kidOrder)