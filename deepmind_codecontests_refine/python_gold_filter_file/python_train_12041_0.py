n = int(input())

if n in range(2, 5+1):
    print("-1")
    for i in range(2, n+1):
        print("1", i)
else:
    # Wrong Answer
    print("1 2")
    p = n // 2 - 2
    for i in range(p+1):
        print("2", i+3)
    for i in range(n-p-3):
        print("1", i+p+4)
    # Right Answer
    for i in range(n - 1):
        print("1", i + 2)