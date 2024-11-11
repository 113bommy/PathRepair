s = int(input())
for __ in range(s):
    a = 0
    b = list()
    bb = list()
    n = int(input())
    ss = input()
    b = ss.split()
    for num in range(n):
        b[num] = int(b[num])
    bb = sorted(b)
    for numm in range(0,n-1,1):
        if bb[numm] == bb[numm+1]:
            a = 1
            break
    if a == 0:
        print("NO")
    else:
        print("YES")
    