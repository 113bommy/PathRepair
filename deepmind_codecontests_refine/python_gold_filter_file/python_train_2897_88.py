def is_good_grid():
    for r in range(n):
        for c in range(r):
            if t[r][c] != t[c][r]:
                return False
    return True


n = int(input())
s = tuple(input() for _ in range(n))

# (0,0)==(1,1)==...==(n-1,n-1)
# colのオフセットだけ変化させる
# それぞれのループで、n個の状態(0,k)==(1,k+1)==...を扱う

ans = 0
for k in range(n):
    t = [[''] * n for _ in range(n)]
    for r in range(n):
        for c in range(n):
            t[r][c] = s[r][(c + k) % n]
    if is_good_grid():
        ans += n
print(ans)
