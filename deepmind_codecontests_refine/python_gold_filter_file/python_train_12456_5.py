n = int(input())
z = list(map(int, input().split()))
z.insert(0, 0)
for x in range(1, n + 1):
    if z[z[z[x]]] == x:
        print("YES")
        exit()

print("NO")

