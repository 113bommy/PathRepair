W, a, b = map(int, input().split())
print(max(b-W-a, a-W-b, 0))