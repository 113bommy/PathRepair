r, c = map(int, input().split())
if r == 1 and c == 1:
    print(0)
elif c == 1:
    for i in range(r):
        print(i+2)
else:
    for i in range(r):
        print(*((i+1)*(r+j+1) for j in range(c)))