n = int(input())
al = [int(input()) for _ in range(n)]

pos = 0
for i in range(n):
    pos = al[pos] - 1
    if (pos == 1):
        print(i+1)
        exit()
print(-1)
