N = int(input())
for _ in range(N):
    n = int(input())
    if n < 10:
        print(n)
        continue
    ans = n
    while n >= 10:
        ans += n // 10
        n = n % 10 + n // 10
        #  print(n)
    print(ans)
    #  print("~~~~~~")
