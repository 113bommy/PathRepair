a, b = map(int, input().split(':'))

m, n = 12, 00

minute = ((b - n) % 60) * 6
hour = ((a - m) % 12 + (b / 60)) * 30

print(hour, minute)
