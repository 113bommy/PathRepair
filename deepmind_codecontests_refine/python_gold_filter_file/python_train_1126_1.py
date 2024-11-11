N, C = map(int, input().split())
X, V = [], []
for i in range(N):
    xi, vi = map(int, input().split())
    X.append(xi)
    V.append(vi)

r_cal = [0]
l_cal = [0]
for i in range(N):
    r_cal.append(r_cal[-1] + V[i])
    l_cal.append(l_cal[-1] + V[N-i-1])

# 折り返さないパターン and 折り返してどこまでいくのか
r_straight = r_cal.copy()
l_straight = l_cal.copy()

for i in range(1, N+1):
    r_straight[i] -= X[i-1]
    l_straight[i] -= (C - X[N-i])

# 折り返すパターン
for i in range(1, N+1):
    r_cal[i] -= 2*X[i-1]
    l_cal[i] -= 2*(C - X[N-i])

# 折り返した後どこまで行くのが最適か
r_max = [0]
l_max = [0]
for i in range(1, N+1):
    r_max.append(max(r_max[-1], r_straight[i]))
    l_max.append(max(l_max[-1], l_straight[i]))

ans = max(r_max[-1], l_max[-1])
for i in range(N):
    ans = max(ans, r_cal[i] + l_max[N-i])
    ans = max(ans, l_cal[N-i] + r_max[i])
    
print(ans)