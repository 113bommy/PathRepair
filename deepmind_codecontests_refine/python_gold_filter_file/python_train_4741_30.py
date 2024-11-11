n = int(input())
if n == 1:
    print(1)
elif n == 2:
    print(1)
else:
    tot = n//3
    rem = n%3
    ans = tot*2
    if rem:
        ans += 1
    print(ans)