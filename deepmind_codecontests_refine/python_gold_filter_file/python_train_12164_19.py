N = int(input())
T = list(map(int, input().split()))
V = list(map(int, input().split()))

V = [0] + V + [0]

# 0.前処理
# N+2個の条件をつくる
left = [0]
right = [0]

for i in range(N):
    left.append(right[i])
    right.append(left[-1]+T[i])
    
left.append(right[-1])
right.append(right[-1])

INF = float("inf")
vel = [INF]*(2*right[-1]+1)

# 1.各ステップでの許容測度の最大値の最小値を求める
for t in range(2*right[-1]+1):
    for i in range(N+2):
        if (t/2) < left[i]:
            vel[t] = min(vel[t], -(t/2)+(V[i]+left[i]))
        elif left[i] <= (t/2) and (t/2) <= right[i]:
            vel[t] = min(vel[t], V[i])
        elif (t/2) > right[i]:
            vel[t] = min(vel[t], (t/2)+(V[i]-right[i]))
            

# 2.面積を求める
ans = 0
for t in range(2*right[-1]):
    ans += (1/2)*0.5*(vel[t]+vel[t+1])
    
print(ans)