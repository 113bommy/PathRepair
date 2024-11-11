a = int(input())
print(*((9 + a, 9) if a % 2 else (4 + a, 4)))
