from collections import defaultdict

n = int(input())
a = input()
b = input()

count = 0
m = n // 2
p = (n - 1) // 2
if n % 2 == 1:
    if a[m] != b[m]:
        count += 1

for i in range(m + (n) % 2):
    d = defaultdict(int)

    d[a[m + i]] += 1
    d[a[p - i]] += 1
    d[b[m + i]] += 1
    d[b[p - i]] += 1

    if all([(i + 1) % 2 for i in d.values()]):
        continue

    if b[m + i] == b[p - i] or a[m + i] == b[m + i] or a[m + i] == b[p - i] or a[p - i] == b[m + i] or a[p - i] == b[
        p - i]:
        count += 1
    else:
        count += 2

print(count)
