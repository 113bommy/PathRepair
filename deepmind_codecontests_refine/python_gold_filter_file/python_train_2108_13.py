import sys
input = sys.stdin.readline

inf = 100000000000000000  # 1e17
mod = 998244353


ANS = [0] *40



def check(x):

    sum = x + 1
    for day in range(x):
        base = x - day
        maxnum = 1 << day

        delta = n - sum
        need = delta // base
        ANS[day] = min(maxnum, need)
        sum += ANS[day] * base
    if sum < n:
        return False
    return True


for CASES in range(int(input())):
    n = int(input())
    l = 0
    r = 35

    ans = r
    while l <= r:
        mid = (l + r) // 2
        if check(mid):
            r = mid - 1
            ans = mid
        else:
            l = mid + 1


    # print(check(1),check(2),check(3))

    print(ans)
    check(ans)
    for i in range(ans):
        print(ANS[i], end=" ")
    print()
