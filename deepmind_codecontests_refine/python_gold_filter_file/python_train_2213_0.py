# Fast IO (only use in integer input)

import os,io
input=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

n,m = map(int,input().split())
x,k,y = map(int,input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
aAlive = [False] * n
index = 0
notPossible = False
for elem in b:
    while index <= n-1 and a[index] != elem:
        index += 1
    if index > n-1 or a[index] != elem:
        notPossible = True
        break
    aAlive[index] = True
if notPossible:
    print(-1)
else:
    cost = 0
    lastAlive = -1
    for i in range(n + 1):
        if i <= n-1 and aAlive[i] == False:
            continue
        elif lastAlive == i - 1:
            lastAlive = i
            continue
        else:
            if x > k * y: # Berserk is cheaper
                alivePerson = i - lastAlive - 1
                maxEdgePower = 0
                if lastAlive >= 0:
                    maxEdgePower = a[lastAlive]
                if i <= n-1 and maxEdgePower < a[i]:
                    maxEdgePower = a[i]
                edgeStrong = True
                for j in range(lastAlive + 1,i):
                    if a[j] > maxEdgePower:
                        edgeStrong = False
                        break
                if edgeStrong:
                    cost += y * alivePerson
                else:
                    if alivePerson >= k:
                        cost += x + y * (alivePerson - k)
                    else:
                        notPossible = True
                        break
            else: # Fireball is cheaper or same
                alivePerson = i - lastAlive - 1
                if alivePerson >= k:
                    cost += x * (alivePerson // k) + y * (alivePerson % k)
                else:
                    maxEdgePower = 0
                    if lastAlive >= 0:
                        maxEdgePower = a[lastAlive]
                    if i <= n-1 and maxEdgePower < a[i]:
                        maxEdgePower = a[i]
                    edgeStrong = True
                    for j in range(lastAlive + 1,i):
                        if a[j] > maxEdgePower:
                            edgeStrong = False
                            break
                    if edgeStrong:
                        cost += y * alivePerson
                    else:
                        notPossible = True
                        break
            lastAlive = i
    if notPossible:
        print(-1)
    else:
        print(cost)

