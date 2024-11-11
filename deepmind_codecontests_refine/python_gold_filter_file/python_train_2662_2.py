n, a, b = map(int, input().split())
aero = input()
if aero[a - 1] == aero[b - 1]:
    print(0)
else:
    print(1)