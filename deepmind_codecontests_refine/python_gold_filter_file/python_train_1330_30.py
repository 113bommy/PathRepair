n = int(input()) % 10
print('bon' if n == 3 else 'pon' if n == 0 or n == 1 or n == 6 or n == 8 else 'hon')