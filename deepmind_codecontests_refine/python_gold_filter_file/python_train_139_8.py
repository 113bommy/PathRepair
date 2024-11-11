n = int(input())
home = []
guest = []
ans = 0
for i in range(n):
    b = input().split()

    home.append(b[0])
    guest.append(b[1])
for i in range(n):
    for j in range(n):
        if home[i] == guest[j]:
            ans = ans + 1
print(ans)
