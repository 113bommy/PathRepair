print('\n'.join([str(i * (i + 1) * (i + 1) - (i - 1)) if i != 1 else '2' for i in range(1, int(input()) + 1)]))
