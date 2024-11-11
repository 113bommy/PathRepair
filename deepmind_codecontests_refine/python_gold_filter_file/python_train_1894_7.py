q = int(input())
while q:
    tem = [0] * 31
    q -= 1
    n = int(input())
    l = list(map(int, input().split()))
    for i in l:
        tem[len(bin(i)[2:]) - 1] += 1
    for i in range(0, 11):
        t = tem[i] // 2
        tem[i + 1] += t
    if tem[11] >= 1: print("YES")
    else: print("NO")