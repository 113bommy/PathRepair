n = int(input())
a = list(map(int,input().split()))
b = max(a)
d = 0
x = 0
def HCF(x,y):
    if x > y:
        smaller = y
        larger = x
    else:
        smaller = x
        larger = y
    while smaller > 0:
        smaller, larger = larger % smaller, smaller
    return larger
for i in a:
    d = HCF(d, b-i)
for i in a:
    x = x+b-i
x = x//d
print(x,d)
