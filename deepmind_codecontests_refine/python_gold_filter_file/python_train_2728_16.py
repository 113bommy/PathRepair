T = int(input())
for t in range(T):
    n = int(input())
    a = list(map(int,input().split()))
    done = False
    for i in range(1, n):
        if abs(a[i] - a[i-1]) > 1:
            print('YES')
            print(i, i+1)
            done = True
            break
    if not done:
        print('NO')
    