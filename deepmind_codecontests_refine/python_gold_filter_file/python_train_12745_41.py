n, p, k = map(int, input().split())
if p - k > 1:
    print("<<", end = ' ')
for i in range(max(1, p - k), min(p + k + 1, n + 1)):
    if i == p:
        print("(", i, ")", sep = '', end = ' ')
    else:
        print(i, end = ' ')
if p + k < n:
    print(">>")