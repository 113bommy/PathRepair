# numChar種類で条件を満たせるかを判定する
def check(As, numChar):
    Ss = [(-1, -1)]
    APrev = As[0]
    for A in As[1:]:
        if APrev >= A: # 文字列長が同じor短くなる場合
            if numChar == 1: return False
            # A文字目より後ろを削除する
            while Ss[-1][0] > A:
                Ss.pop()
            # A文字目を[+1]する
            posS = A
            while Ss[-1] == (posS, numChar - 1):
                Ss.pop()
                posS -= 1
            if posS == 0:
                return False
            elif Ss[-1][0] == posS:
                Ss[-1] = (posS, Ss[-1][1] + 1)
            else:
                Ss.append((posS, 1))
        APrev = A
    return True

# 条件を満たす最小のnumCharを二分探索する
def solve(As, N):
    lft, rgt = 0, N
    while rgt - lft > 1:
        mid = (lft + rgt) // 2
        isOK = check(As, mid)
        if isOK:
            rgt = mid
        else:
            lft = mid
    return rgt

N = int(input())
As = list(map(int, input().split()))

print(solve(As, N))
