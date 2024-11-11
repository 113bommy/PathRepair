cn = 10**9 + 7
c = 2 * cn
f = [1]
for i in range(1, (10**5) * 2 + 5):
    f.append((f[-1] * i) % c)

for i in range(int(input())):
    n = int(input())
    print(f[2 * n] // 2)

