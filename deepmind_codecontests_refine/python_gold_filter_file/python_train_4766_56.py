X, Y = map(int, input().split())
if X*2 <= Y <= X*4 and Y % 2 == 0:
    print('Yes')
else:
    print('No')