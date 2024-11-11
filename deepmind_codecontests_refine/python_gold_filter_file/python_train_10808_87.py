a, b, c, d = map(int, input().split())
print('Yes' if abs(a-c) <= d or max(abs(a-b), abs(b-c)) <= d else 'No')
