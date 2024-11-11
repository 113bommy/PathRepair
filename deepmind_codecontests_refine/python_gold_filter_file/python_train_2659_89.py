a = list(map(int, input().split()))
b = list(map(int, input().split()))
counter = 0
for i in b:
    if i > a[1]:
        counter += 2
    else:
        counter += 1
print(counter)