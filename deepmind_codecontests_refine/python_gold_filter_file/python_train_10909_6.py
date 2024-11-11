
N = int(input())
S = input()

ans = 0
for n in range(1000):
    target = "{:03}".format(n)
    j = 0
    for i in range(N):
        if S[i] == target[j]:
            j += 1
        if j == 3:
            ans += 1
            break

print(ans)
