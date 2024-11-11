buckets = {chr(ord('A') + i): 0 for i in range(26)}
for c in (input() + input()):
    buckets[c] += 1

for c in input():
    buckets[c] -= 1
if sum([1 for k, v in buckets.items() if v == 0]) == 26:
    print('YES')
else:
    print('NO')