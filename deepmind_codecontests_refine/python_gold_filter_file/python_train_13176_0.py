n , m = map(int , input().split())
nl , ml , cl = [] , [] , []
for i in range(n):
    nl.append(input())
for j in range(m):
    x = input()
    if x not in nl :
        ml.append(x)
    else:
        cl.append(x)
print('YES' if (len(nl)-len(cl) + len(cl) % 2)  > len(ml) else 'NO')