a, b, c = map(int, input().split())
print(b+c if a+b >= c else b*2+a+1)
