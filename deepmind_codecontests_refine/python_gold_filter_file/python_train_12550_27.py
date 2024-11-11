count_ch, timeout = map(int, input().split())
time = list(map(int, input().split()))
calc = 1
for i in range(1, count_ch):
    a = time[i-1]
    b = time[i]
    if b - a > timeout:
        calc = 0
    calc += 1
print(calc)