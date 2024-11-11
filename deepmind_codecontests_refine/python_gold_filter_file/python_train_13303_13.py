
T1, T2 = list(map(int, input().split()))
A1, A2 = list(map(int, input().split()))
B1, B2 = list(map(int, input().split()))


L1 = T1 * (A1- B1)
L2 = L1 + T2 * (A2- B2)

if L1 * L2 > 0:
    print(0)
elif L2 == 0:
    print("infinity")
else:
    M = (-L1) / L2
    ans = 2 * int(M) + 1
    if float(int(M)) == M:
        ans -= 1
    print(ans)

