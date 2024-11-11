a, b, c = map(int, input().split())
c/=100
a*=c
a*=10
finals = 0
if a%10 > 0:
    a/=10
    finals = int(a)+1
else:
    a/=10
    finals = int(a)
if finals <= b:
    finals = 0
    print(finals)
else:
    print(finals-b)