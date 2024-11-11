n = int(input())
line = tuple(map(int, input().split()))

for i in range(n):
    town = line[i]
    len1 = abs(town - line[0])
    len2 = abs(town - line[n-1])
    if len1 > len2 : maxlen = len1
    else: maxlen = len2

    if i == 0: minlen = abs(town - line[i+1])
    elif i == (n-1): minlen = abs(town - line[i-1])
    else:
        len1 = abs(town - line[i-1])
        len2 = abs(town - line[i+1])
        if len1 > len2: minlen = len2
        else: minlen = len1

    print(minlen, maxlen)
