t = int(input())

for _ in range(t):
    n, k = map(int, input().split())

    s = input()
    a = [int(x) for x in s]
    
    z = 0
    res = 0
    check = 0
    val = 0
    for i in range(n):
        if a[i] == 0:
            z += 1
        else:
            if val == 0:
                res += (z//(k+1))
            else:
                res += ((z-k)//(k+1))
            val = 1
            z = 0
            check = 1
    
    if check == 0:
        res += max(1, z//(k+1))
        if z - (z//(k+1))*(k+1) != 0 and z//(k+1) != 0:
            res += 1
    else:
        res += z//(k+1)
    print(res)