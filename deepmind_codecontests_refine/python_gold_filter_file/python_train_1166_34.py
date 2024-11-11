a = int(input())
b = int(input())
c = int(input())
d = int(input())
e = int(input())
f = int(input())
b = min(min(b,c),d)
a = min(a,d)
if e > f:
    print(e * a + f * min((d-a),b))
else:
    print(f * b + e * min((d-b),a))
