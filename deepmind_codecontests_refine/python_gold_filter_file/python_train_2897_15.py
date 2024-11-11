def solve():
    global S, N
    N = int(input())

    S = []
    for n in range(N):
        S.append(list(input()))


    res = 0
    for n in range(N):
        if check(n):
            res += N

    print(res)

def check(move):
    for i in range(N):
        for j in range(i+1, N):
            if S[(i-move)%N][j] != S[(j-move)%N][i]:
                return False
    return True


if __name__ == "__main__":
    solve()