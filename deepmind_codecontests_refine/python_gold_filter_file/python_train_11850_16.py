N, M = map(int, input().split())
x = M//N
max = 1
for i in range(x, 0, -1):
    mod = M - (N-1)*i
    if mod%i == 0:
        max = i
        break
print(max)