n = int(input())
box = list(map(int, input().split()))
used = [False for i in range(n)]
accepted = [False for i in range(n)]
j = 0
for i in box:
    if i <= n and not used[i - 1]:
        accepted[j] = True
        used[i - 1] = True
    j += 1
j = 0
for i in range(n):
    if not accepted[i]:
        while used[j] != False:
            j += 1
        j += 1
        print(j, end=' ')
    else:
        print(box[i], end=' ')
        