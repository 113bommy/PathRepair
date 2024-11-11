from collections import defaultdict

t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().strip().split()))

    rooms = set()
    good = True
    for k in range(n):
        value = (k + a[k % n]) % n 
        if value in rooms:
            good = False
            break
        rooms.add(value)
    
    if good:
        print('YES')
    else:
        print('NO')