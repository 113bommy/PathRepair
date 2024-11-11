from collections import Counter
n = int(input())
c = Counter(input())
commons = c.most_common()
max_cnt = 0
for x in commons:
    if commons[0][1] == x[1]:
        max_cnt += 1
ans = 1
for i in range(n):
    ans *= max_cnt
    ans = ans % (1000000007)
print(ans)
