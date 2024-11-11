N = int(input())
As = sorted(map(int, input().split()))

used = [False] * N

ans = 0
for i in range(31, 0, -1):
    power_of_two = 1 << i
    l = 0
    r = N - 1
    while True:
        while l < N and used[l]:
            l += 1
        while r >= 0 and used[r]:
            r -= 1
        if l >= r:
            break

        if As[l] + As[r] == power_of_two:
            used[l] = True
            used[r] = True
            l += 1
            r -= 1
            ans += 1
        elif As[l] + As[r] < power_of_two:
            l += 1
        else:
            r -= 1

print(ans)

