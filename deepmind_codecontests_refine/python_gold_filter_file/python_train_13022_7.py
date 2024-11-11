n, m = map(int, input().split())
c = 0
otrezki = []
answer = []
while c < n:
    l, r = map(int, input().split())
    if l == r:
        otrezki.append(l)
    else:
        while l <= r:
            otrezki.append(l)
            l += 1
    c += 1

for i in range(1, m + 1):
    if i not in otrezki:
        answer.append(str(i))

print(len(answer), '\n', ' '.join(answer) )
# print(' '.join(answer))
