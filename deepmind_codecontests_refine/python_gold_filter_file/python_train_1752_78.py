a,b,c,k = map(int, input().split())

ans = a - b

if(k % 2 == 1):
    ans = b - a

print(ans)