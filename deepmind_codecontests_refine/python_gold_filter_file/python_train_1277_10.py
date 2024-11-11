from math import gcd


t = int(input())
ans = []


for i in range(t):
    n = int(input())
    arr = list(map(int, input().split()))

    b = []
    curr = max(arr)
    b.append(curr)
    arr.remove(curr)
    cd = curr

    while arr:
        curr = max(arr, key=lambda x: gcd(x, cd))
        b.append(curr)
        arr.remove(curr)
        cd = gcd(cd, curr)
    
    ans.append(b)


for el in ans:
    print(" ".join(list(map(str, el))))