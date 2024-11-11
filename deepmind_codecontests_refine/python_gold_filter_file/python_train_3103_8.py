n = int(input())
w = list(map(int, input().split()))
l = []
for t in range(1, n):
    l.append(abs(sum(w[t:]) - sum(w[:t])))
print(min(l))