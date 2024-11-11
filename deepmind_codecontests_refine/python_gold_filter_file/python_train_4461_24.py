a, b, c = map(int, input().split())
print(b if a==c else c if a==b else a)