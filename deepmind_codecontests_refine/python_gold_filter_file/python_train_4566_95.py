w, a, b = map(int, input().split())
print(max(0, max(a,b)-(w+min(a,b))))