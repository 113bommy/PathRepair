import math
n = int(input())
arr = list(map(int, input().split()))
arr.sort()
#print(arr)
x = arr[-1]
gd = 0
arr2 = list(set(arr))
arr2.sort()
#print(arr2)
for k in arr2:
    if arr.count(k) == 2:
        gd = max(gd, k)
#print(gd)
smh = arr2.index(gd)
#print(smh)
#for kk in range(smh + 1, len(arr2)):
for kk in range(len(arr2) - 1, smh - 1, -1):
    #print(kk)
    if math.gcd(arr2[kk], x) == gd:
        print(arr2[kk], x)
        exit()
print(x, x)
