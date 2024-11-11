X, Y = map(int, input().split())

points = [-1, 300000, 200000, 100000, 0]
print(400000*(X==Y==1) + points[min(4, X)] + points[min(4, Y)])