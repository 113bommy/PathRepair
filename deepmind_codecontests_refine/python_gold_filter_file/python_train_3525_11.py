N = int(input())
t0, a0 = 1, 1
for _ in range(N):
    t, a = map(int, input().split())
    n = max((t0- 1)// t+ 1, (a0-1)//a+1)
    t0, a0 = n*t, n*a

print(t0 + a0)