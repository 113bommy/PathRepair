from collections import Counter
n = int(input())
A = sorted(list(map(int, input().split())))[-1::-1]
c = Counter(A)
ans = 0
for a in A:
    b = (1<<a.bit_length()) - a
    if a == b and c[a] > 1:
        c[a] -= 2
        ans += 1
    elif a != b and c[a] > 0 and c[b] > 0:
        c[a] -= 1
        c[b] -= 1
        ans += 1
print(ans)
