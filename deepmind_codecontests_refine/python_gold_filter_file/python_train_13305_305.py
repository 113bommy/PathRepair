A,B = map(int,input().split())
x = A + B if B % A == 0 else B - A
print(x)