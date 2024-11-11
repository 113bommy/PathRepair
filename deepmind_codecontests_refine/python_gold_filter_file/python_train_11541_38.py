A, B, C = map(int, input().split())
for k in range(B):
    if (k * A) % B == C: print("YES"); exit()
print("NO")
