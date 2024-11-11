n = int(input())
count = 0
for i in range(n):
    p, q = map(int,input().split())
    vacant_seats = q - p
    if vacant_seats >= 2:
        count += 1
print(count)