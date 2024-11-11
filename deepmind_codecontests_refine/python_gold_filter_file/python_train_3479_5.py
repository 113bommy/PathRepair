n, p = input(), [0] * 5001
for i in map(int, input().split()): p[i] += 1
a = [i for i in range(1, 5001) if p[i]]
b = [i for i in a[: -1] if p[i] > 1]
print(len(a) + len(b))
print(' '.join(map(str, a)) + ' ' + ' '.join(map(str, reversed(b))))