x,y = map(int,input().split())
c = 0
d = y//x
while 2**c <= d:
    c += 1
print(c)