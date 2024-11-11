N,D = map(int,input().split())
XY = [list(map(int,input().split())) for _ in range(N)]
print(sum([x**2 + y**2 <= D**2 for x,y in XY]))