n, m = map(int, input().split())

count = 1
for i in range((m//n), 0, -1):
    if m % i == 0:
        count = i
        break

print(count)