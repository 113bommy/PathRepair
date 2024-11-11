n = int(input())

sum = 0

for i in range(n):
    s0, s1 = map(int, input().split())
    if s1-s0 >= 2:
        sum += 1

print(sum)