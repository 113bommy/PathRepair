N = int(input())

ans = ''
while N != 0:
    r = N % 2
    N = (N - r) // (-2)
    ans += str(r)

ans = ans[::-1]
if ans == '':
    ans = '0'

print(ans)