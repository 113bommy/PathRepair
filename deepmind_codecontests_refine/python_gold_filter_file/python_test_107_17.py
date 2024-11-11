import sys
input = sys.stdin.readline
t = int(input())
for _ in range(t):
    n, a, b = map(int, input().split())
    k = sorted(range(1, n+1))
    if abs(a-b) > 1:
        print(-1)
        continue

    if n == 2 and not a+b==0:
        print(-1)
        continue
    rep = min(a, b)
    if b > a:
        k[0], k[1] = k[1], k[0]
        for i in range(2, 2*(rep+1), 2):
            if i+1 >= n-1:
                print(-1)
                break
            k[i], k[i+1] = k[i+1], k[i]
        else:
            print(*k)

    elif a > b:
        k[-1], k[-2] = k[-2], k[-1]
        for i in range(1, 2*(rep)+1, 2):
            if i+1 >= n-2:
                print(-1)
                break
            k[i], k[i+1] = k[i+1], k[i]
        else:
            print(*k)

    else:
        for i in range(1, 2*(rep)+1, 2):
            if i+1 >= n-1:
                print(-1)
                break
            k[i], k[i+1] = k[i+1], k[i]
        else:
            print(*k)


