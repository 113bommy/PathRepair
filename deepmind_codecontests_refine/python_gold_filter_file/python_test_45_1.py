t = int(input())
for x in range(t):
    n = int(input())
    z = 1
    s = list(map(int,input().split()))
    for i in range(n):
        if s[i] == 1:
            z += 1
        if i >= 1 and s[i] == 1 and s[i-1] == 1:
            z += 4
        if i >= 1 and s[i] == 0 and s[i-1] == 0:
            z = -1
            break
    print(z)
