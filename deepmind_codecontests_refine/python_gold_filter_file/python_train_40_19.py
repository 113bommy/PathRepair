a,b = input().split(' ')

a,b = int(a),int(b)
c = 0
h = 0

while a > 0:
    h += a
    c += a
    a = int(c/b)
    c = c%b


print(h)