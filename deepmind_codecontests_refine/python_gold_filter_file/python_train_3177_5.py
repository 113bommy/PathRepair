num = 3
first = list(map(int, input().split()))
second = list(map(int, input().split()))
for i in range(num):
    while first[i] - 2 >= second[i]:
        if first[(i + 1) % 3] < second[(i + 1) % 3]:
            first[(i + 1) % 3] += 1
        else:
            first[(i + 2) % 3] += 1
        first[i] -= 2
        
for i in range(num):
    if first[i] < second[i]:
        print('No')
        break
else:
    print('Yes')