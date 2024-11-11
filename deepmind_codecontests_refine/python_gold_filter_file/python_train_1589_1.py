tests = int(input())

sol = []

while tests:
    tests -= 1

    x,y,n = (int(i) for i in input().split())

    h = n//x*x
    h += y
    while h > n:
        h -= x

    sol.append(h)

for i in sol:
    print(i)