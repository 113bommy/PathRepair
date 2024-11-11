import sys

n = int(sys.stdin.readline())
arr = list(sys.stdin.readline().rstrip())
if n % 2 == 1:
    print(-1)
else:
    o = 0
    c = 0
    for i in arr:
        if i == '(':
            o += 1
        else:
            c += 1
    if o != c:
        print(-1)
    else:
        temp = [0] * (n + 1)
        if arr[0] == '(':
            temp[1] = 1
        else:
            temp[1] = -1
        for i in range(2, n + 1):
            if arr[i - 1] == '(':
                temp[i] = temp[i - 1] + 1
            else:
                temp[i] = temp[i - 1] - 1
        ans = 0
        for i in range(n):
            if (temp[i] < 0 and temp[i + 1] <= 0) or (temp[i] <= 0 and temp[i + 1] < 0):
                ans += 1
        print(ans)