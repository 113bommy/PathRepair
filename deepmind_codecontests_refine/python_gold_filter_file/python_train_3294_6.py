t = int(input())
for i in range(t):
    n, k = map(int, input().split())
    K = list(map(int, input().split()))
    Lenght = []
    Lenght.append(K[0])
    for j in range(1, k):
        Lenght.append(K[j] - K[j - 1] + 1)
    Lenght.append(n - K[k - 1] + 1)
    sec = []
    for m in range(len(Lenght)):
        if m == 0 or m == len(Lenght) - 1:
            sec.append(Lenght[m])
        else:
            sec.append((Lenght[m] + 1) // 2)
    ans = max(sec)
    print(ans)