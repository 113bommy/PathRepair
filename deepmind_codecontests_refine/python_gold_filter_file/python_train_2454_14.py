a = int(input())
b = int(input())
c = int(input())
if b >= 2 and c >= 4:
    for i in range(a, 0, -1):
        if b >= i*2 and c >= i*4:
            print(i*7)
            break
else:
    print(0)