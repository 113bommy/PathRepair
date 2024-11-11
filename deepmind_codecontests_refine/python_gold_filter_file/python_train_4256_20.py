N = int(input())
X = sorted(list(map(int, input().split())))
s = 0
for i in range(N):
    s += X[2*i]
print(s)
