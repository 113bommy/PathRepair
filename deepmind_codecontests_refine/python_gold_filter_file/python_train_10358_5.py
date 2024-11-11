def f(a, b, c, t):
    if t == '**': return a * b * c
    if t == '++': return a + b + c
    if t == '*+': return a * b + c
    if t == '+*': return a * (b + c)

a, b, c, d = sorted(list(map(int, input().split())))
t = input()[:: 2]
if t == '*+*': print(a * (b * c + d))
elif t == '**+': print(a * d + b * c)
elif t[0] == '*':
    a, b, c = sorted([a * b, c, d])
    print(f(a, b, c, t[1: ]))
else: print(f(a, b, c + d, t[1: ]))