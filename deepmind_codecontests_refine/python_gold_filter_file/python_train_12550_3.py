c = input().split()[1]
count = 0
prev = 0

for k in input().split():
    if int(k) - prev <= int(c):
        count += 1
    else:
        count = 1
    prev = int(k)

print(count)