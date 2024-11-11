n, k = list(map(int, input().split()))
w = list(map(int, input().split()))
counter = 0
for i in w:
    current = i / k
    if int(current) != current:
        current = int(current) + 1
    counter += current
counter /= 2
if int(counter) != counter:
    counter = int(counter) + 1
print(int(counter))
