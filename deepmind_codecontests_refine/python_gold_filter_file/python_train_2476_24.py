a, b, c, d = map(int, input().split())
print('YNeos'[-(-a//d) < -(-c//b)::2])
