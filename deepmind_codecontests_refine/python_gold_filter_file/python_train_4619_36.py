n = int(input())

c = 0
for i in range(n):
    a = input().replace('0', '').replace(' ', '')
    if len(a) > 1:
        c += 1
print(c)