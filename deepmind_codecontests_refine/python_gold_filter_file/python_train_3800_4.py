from math import *
n, m = map(int, input().split())
answer = 0
# for i in range(1, n + 1):
#     for j in range(1, n + 1):
#         print(i * j, end=' ')
#     print()

for i in range(1, int(sqrt(m))):
    if m % i == 0 and m // i <= n:
        answer += 1
answer *= 2
if m % int(sqrt(m)) == 0 and m // int(sqrt(m)) <= n and int(sqrt(m)) != m // int(sqrt(m)):
    answer += 2
   # print(int(sqrt(m)) != m % int(sqrt(m)), int(sqrt(m)), m % int(sqrt(m)))
elif int(sqrt(m)) ** 2 == m and int(sqrt(m)) <= n:
    answer += 1
print(answer)