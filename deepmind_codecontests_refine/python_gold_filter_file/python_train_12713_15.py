n, k = map(int, input().split(" "))
r = 2 * n
g = 5 * n
b = 8 * n
answer = 0
if r > 0:
    answer += r//k
    if r % k != 0:
        answer += 1
if g > 0:
    answer += g//k
    if g % k != 0:
        answer += 1

if b > 0:
    answer += b//k
    if b % k != 0:
        answer += 1


print(answer)