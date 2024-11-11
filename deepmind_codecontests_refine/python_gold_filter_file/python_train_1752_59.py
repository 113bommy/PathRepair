a, b, _, k = map(int, input().split())
print((a - b)*((-1)**(k & 1)))