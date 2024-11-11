n = list(map(int, input().split()))
m = list(map(int, input().split()))
counter = 0
for i in m:
    if i > n[1]:
        counter += 2
    else:
        counter += 1
print(counter)
