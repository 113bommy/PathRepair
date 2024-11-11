n = int(input())

if n <= 5:
    print(-1)
else:
    n3 = (n - 1) // 2
    n2 = n - n3 - 1
    for i in range(n2):
        print(1, i+2)
    for i in range(n3):
        print(2, i+n2+2)

for i in range(n-1):
    print(1, i+2)
