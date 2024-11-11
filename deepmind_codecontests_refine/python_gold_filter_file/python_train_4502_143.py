ts = int(input())
for t in range(ts):
    n = int(input())
    if n < 3:
        print(0)
    else:
        print((n-1)//2)