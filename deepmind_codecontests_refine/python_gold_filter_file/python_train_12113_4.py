x, t, a, b, d_a, d_b = map(int, input().split())

answer = 'NO'
if x == 0:
    answer = 'YES'
if a - x >= 0 and (a - x) // d_a < t and (a - x) % d_a == 0:
    answer = 'YES'
elif b - x >= 0 and (b - x) // d_b < t and (b - x) % d_b == 0:
    answer = 'YES'
else:
    for i in range(t):
        s = a + b - x - d_a * i
        if s < 0: 
            break
        if s // d_b < t and s % d_b == 0:
            answer = 'YES'
            break

print(answer)