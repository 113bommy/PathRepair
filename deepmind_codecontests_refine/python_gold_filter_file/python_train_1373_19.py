w = list(map(int, input().strip().split()))
b1 = list(map(int, input().strip().split()))
b2 = list(map(int, input().strip().split()))
def intersection(a, b):
    I = [max(a[0], b[0]), max(a[1], b[1]), min(a[2], b[2]), min(a[3], b[3])]
    return I
def area(a):
    aria = max(0, a[2]-a[0])*max(0, a[3]-a[1])
    return aria
A = area(intersection(w,b1)) + area(intersection(w,b2)) - area(intersection(w, intersection(b1,b2)))
if A == area(w):
    print('NO')
else:
    print('YES')
