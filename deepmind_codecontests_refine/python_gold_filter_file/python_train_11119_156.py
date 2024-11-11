l = [int(input()) for _ in range(5)]
print('Yay!' if max(l) - min(l) <= int(input()) else ':(')