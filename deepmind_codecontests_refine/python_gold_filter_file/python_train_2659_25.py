n,  h = input().split()
arr = input().split()
counter = 0

for i in arr:
    if int(h) >= int(i):
        counter += 1
    if int(h) < int(i):
        counter += 2

print(counter)
