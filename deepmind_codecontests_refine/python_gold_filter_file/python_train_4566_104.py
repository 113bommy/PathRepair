w, a, b = map(int, input().split())
print(max(a-b-w, 0, b-a-w))
