N = int(input())
ans = ''
while N:
    N -= 1
    ans += chr(ord('a') + N%26)
    N //= 26
print(ans[::-1])