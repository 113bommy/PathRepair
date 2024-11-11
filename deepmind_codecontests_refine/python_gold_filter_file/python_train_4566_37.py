w, a, b = map(int, input().split())
d = [a-w-b, b-w-a][a<b]
print([0,d][d>0])