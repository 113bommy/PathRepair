a, b, c, d = list(map(int, input().split()))
a_win = a / b
b_loose = 1 - c / d
a_loose = 1 - a_win
result = a_win / (1 - a_loose*b_loose)
print(result)