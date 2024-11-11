x = []
y = []
while True:
    try:
        a, b, p, c, d, q = map(int, input().split())
        x.append((d*p-b*q)/(a*d-b*c))
        y.append((a*q-c*p)/(a*d-b*c))
    except EOFError:
        break

for i in range(len(x)):
    print("{:.3f} {:.3f}".format(x[i]+0, y[i]+0))