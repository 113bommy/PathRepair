import sys
for _ in range(int(sys.stdin.readline())):
    b, w = [int(i) for i in sys.stdin.readline().split()]
    if b > w:
        dif = b - w
        if dif <= 2*w+1:
            print("YES")
            for i in range(2, 2*w+2):
                print(2, i)
            
            if dif & 1:
                print(2, 1)
            for i in range(1, dif//2 + 1):
                print(1, 2*i)
                print(3, 2*i)
        else:
            print("NO")
    else:
        dif = w - b
        if dif <= 2*b+1:
            print("YES")
            for i in range(2, 2*b+2):
                print(2, i)
            
            if dif & 1:
                print(2, 2*b+2)
            for i in range(1, dif//2 + 1):
                print(1, 2*i+1)
                print(3, 2*i+1)
        else:
            print("NO")