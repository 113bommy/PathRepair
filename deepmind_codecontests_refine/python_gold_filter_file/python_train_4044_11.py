N = int(input())
L = [2, 1]
for _ in range(88):
    L.append(L[-1]+L[-2])
print(L[N])
