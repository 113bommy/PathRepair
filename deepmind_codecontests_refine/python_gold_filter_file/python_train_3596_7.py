x, n = map(int,input().split())
count = 0
for i in range(x):
    A,m = input().split()
    m = int(m)
    if A == "+" :
        n = n + m
    elif A == "-" and m <= n:
        n = n - m
    elif m > n and A == "-":
        count = count + 1
print(n,count)