from collections import Counter
n = int(input())
a = list(map(int, input().split()))
a.sort(reverse=True)
c = Counter(a)

ans = 0
for i in a:
    if c[i] == 0:
        continue
    c[i] -= 1
    k = 1<<i.bit_length()
    j = k-i
    if j in c and c[j] > 0:
        ans += 1
        c[j] -= 1
print(ans)
