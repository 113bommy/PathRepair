n, k = [int(x) for x in input().split()]
if k == 1:
    print("1" + "0"*(n-1))
elif 3*k <= n:
    # print("2")
    print(("0" * ((n-k)//2)) + "1" + ("0"*(k-2)) + "1" + "0" * ((n-k)//2))
else:
    tmp = "0" * ((n-k)//2) + "1"
    s = tmp
    s = tmp * (n // len(tmp) + 1)
    s = s[:n]
    print(s)