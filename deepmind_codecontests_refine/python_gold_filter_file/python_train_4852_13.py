n, a = map(int, input().split())

q = 180/n

angle = 0

vars = [abs(q*(i+1)-a) for i in range(n-2)]

minIndex = vars.index(min(vars))
print(2,1,3+minIndex)