# A. Roma and Lucky Numbers

n, k = map(int, input().split())
a = list(map(int, input().split()))

ans = 0
lucky = ['4', '7']
for x in a:
    x_str = str(x)
    count = 0
    for digit in x_str:
        if digit in lucky:
            count += 1
            if count > k:
                break
    if count <= k:
        ans += 1

print(ans)
