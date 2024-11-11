x = [int(input()) for _ in range(6)]
print(':(' if x[-2]-x[0] > x[-1] else 'Yay!')