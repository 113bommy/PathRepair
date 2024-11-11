n = int(input())
pi = list(map(int,input().split()))
if n == 1:
    print(1)
else:
    num = [0]*n
    num[0] = -1
    maxs = [0] * 4
    maxs[0] = pi[0]
    for i in range(1,n):
        if pi[i] > maxs[0]:
            maxs[2] = maxs[0]
            maxs[3] = maxs[1]
            maxs[0] = pi[i]
            maxs[1] = i
        elif pi[i] > maxs[2]:
            maxs[2] = pi[i]
            maxs[3] = i

        if maxs[1] == i:
            num[i] -= 1
        if maxs[3] == i:
            num[maxs[1]] += 1
    max1 = num[0]
    max2 = 0
    for i in range(1,n):
        if num[i] > max1:
            max1 = num[i]
            max2 = i
        if num[i] == max1:
            if pi[max2] > pi[i]:
                max2 = i
    print(pi[max2])
