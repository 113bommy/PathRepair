s, t = [input() for _ in range(2)]
print('Yes' if sorted(s) < sorted(t, reverse=True) else 'No')
