n=int(input())

ans = ''
while n:
    tmp = (n-1)%26
    ans += chr(ord('a')+tmp)
    n-=1
    n//=26
print(ans[::-1])