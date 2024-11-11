a1, a2 = map(int, input().split())

ans = 1 if a1 >= 2 or a2 >= 2 else 0

while a1 >= 3 or a2 >= 3:
    if a1 >= 3:
        a1 -= 2
        a2 += 1
        ans += 1
    elif a2 >= 3:
        a2 -=  2
        a1 += 1
        ans += 1
    


print(ans)
