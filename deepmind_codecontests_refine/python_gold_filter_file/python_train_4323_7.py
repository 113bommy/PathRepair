n = int(input())

for i in range(20, -1, -1):
    if n >= 2**i:
        print(i+1, end=" ")
        n -= 2**i
