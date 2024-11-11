N, M = map(int, input().split())

a = M // N
for i in range(a, 0, -1):
    if M % i == 0:
        print(i)
        break
