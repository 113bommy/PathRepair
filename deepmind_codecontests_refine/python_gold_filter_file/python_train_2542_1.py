n = int(input())
l = [int(x) for x in input().split()]
ans = 0
l.sort()
while(l):
    l1 = []
    c = 0
    for i in range(len(l)):
        if (l[i]>=c):
            c+=1
        else:
            l1.append(l[i])
    l = l1[:]
    ans+=1 
print(ans)