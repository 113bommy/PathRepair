x, b, r = map(int, input().split())
k=int(x/(b+r))
print(k*b+min(x%(b+r), b))