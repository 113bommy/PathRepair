n = int(input())
for i in (4, 6, 8):
    if not (n-i)%3:
        print(i, n-i)
        break