a, b, k = map(int, input().split())
ans = [e for e in range(1, min(a, b) + 1) if (a % e) + (b % e) == 0]
print(ans[-k])