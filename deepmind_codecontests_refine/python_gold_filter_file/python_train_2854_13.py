n = int(input())
A = list(map(int, input().split()))

if n < 2:
    end = n
    cur = n
    ans = n
else:
    end = 2
    cur = 2
    ans = 2
while end < n:
    # print()
    # print(end, A[end])
    if A[end] == A[end - 1] + A[end - 2]:
        cur += 1
    else:
        if ans < cur:
            ans = cur
        cur = 2
    end += 1
if ans < cur:
    ans = cur
print(ans)
