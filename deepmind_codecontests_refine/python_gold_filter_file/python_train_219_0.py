# import numpy as np

def dist(a, b):
    return (b - a) % n

n, m = list(map(int, input().split(" ")))

sweets = {i: [] for i in range(n)}
for i in range(m):
    s, t = list(map(int, input().split(" ")))
    sweets[s - 1].append(t - 1)

t = {i: -1e6 for i in range(n)}

for i in range(n):
    sweets[i] = sorted(sweets[i], key=lambda x: -dist(i, x))
    if len(sweets[i]):
        t[i] = (len(sweets[i]) - 1) * n + dist(i, sweets[i][-1])

# t = np.array([t[i] for i in range(n)], dtype=int)
# raise ValueError("")
# print(t)
result = []

m_max, i_max = 0, 0
for i, v in t.items():
    if v + i > m_max + i_max:
        m_max, i_max = v, i
result.append(m_max + i_max)

for s in range(1, n):
    old_max = t[i_max] + dist(s, i_max)
    new_max = t[s - 1] + dist(s, s - 1)
    if new_max > old_max:
        result.append(new_max)
        i_max = s - 1
    else:
        result.append(old_max)

print(" ".join(map(str, result)))