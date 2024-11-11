a, b, c, d = map(int, input().split())
print("Yes" if min(max(abs(b-a), abs(c-b)), abs(a-c)) <= d else "No")