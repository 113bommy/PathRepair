n = int(input())
a = list(map(int, input().split()))
b = [0] * 1000000
max_i = 0
k = 0
for i in a:
    b[i] += 1
    if i > max_i:
        max_i = i
for i in range(max_i + 1):
    if b[i]:
        if b[i] >= i - k:
            k = i
        else:
            k += b[i]
print(k)
