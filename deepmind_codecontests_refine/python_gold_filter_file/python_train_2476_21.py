a, b, c, d = map(int, input().split())
print('Yes' if -(-c//b) <= -(-a//d) else 'No')