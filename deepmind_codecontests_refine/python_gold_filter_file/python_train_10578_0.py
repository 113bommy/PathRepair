from sys import stdin, stdout


n = int(stdin.readline())
current = 0
ans = 'z'

while n:
    cnt = 0
    
    while cnt * (cnt + 1) // 2 <= n:
        cnt += 1
    
    for i in range(cnt):
        ans += chr(ord('a') + current)
    
    current += 1
    cnt -= 1
    
    n -= cnt * (cnt + 1) // 2

stdout.write(ans)