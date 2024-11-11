n = int(input())
s = list(input())
x = s.count('x')
X = s.count('X')
if X != x:
    print(abs(X - x) // 2)
    if X > x:
        for i in range(n):
            if s[i] == 'X':
                s[i] = 'x'
                X -= 1
                x += 1
            if X == x:
                break
    else:
       for i in range(n):
            if s[i] == 'x':
                s[i] = 'X'
                x -= 1
                X += 1
            if X == x:
                break
    print(''.join(s))
else:
    print(0)
    print(''.join(s))