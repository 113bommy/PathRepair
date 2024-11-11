n , m = map(int,input().split())
h = input()
v = input()
if (h[0] == '>' and v[0] == 'v') or (h[-1] == '<' and v[-1] == '^') or (h[0] == '<' and v[-1] == 'v') or (h[-1] == '>' and v[0] == '^'):
    print('NO')
else:
    print('YES')