import math

L = int(input())
n = int(math.log2(L))

dag = []
for i in range(1, n+1):
    dag.append(' '.join(map(str, [i, i+1, 2**(i-1)])))
    dag.append(' '.join(map(str, [i, i+1, 0])))

for i in range(n, 0, -1):
    if L - 2**(i-1) >= 2**n:
        L -= 2**(i-1)
        dag.append(' '.join(map(str, [i, n+1, L])))

print(n+1, len(dag))
print('\n'.join(dag))
