a, b = map(int,input().split())
while a != 0:
    for i in range(a):
        print('#'*b)
    print()
    a, b = map(int,input().split())
