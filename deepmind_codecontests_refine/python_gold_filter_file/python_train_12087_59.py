n = int(input())
a = list(map(int, input().split()))
for x in range(n):
    if a[x] == 1:
        print("HARD")
        break
else:
    print("EASY")