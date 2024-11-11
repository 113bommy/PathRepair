N = int(input())
X = list(map(int, input().split()))
for i in range(N):
    X[i] -= 14 * (max(0, (X[i] // 14) - 1))
    print("YES" if X[i] in range(15, 21) else "NO")

# Ravens 1
# After testing Sharif ICPC contest
