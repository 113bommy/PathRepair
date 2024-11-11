N, = map(int, input().split())
for _ in range(N):
    a, b = map(int, input().split())
    print(-(-abs(b-a)//10))
