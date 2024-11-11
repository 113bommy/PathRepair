n, k = list(map(int, input().split())) # n is the number of messages and k is the number of conversations that can be shown
ids = list(map(int, input().split()))
screen = [None] * k
convs = 0
if k >= 1:
    for i in ids:
        if i not in screen:
            screen[1:] = screen[0:k-1]
            screen[0] = i
        else:
            continue
for i in screen:
    if i:
        convs += 1
print(convs)
print(*screen[0:convs])













