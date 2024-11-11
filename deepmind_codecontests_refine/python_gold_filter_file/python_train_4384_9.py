w, h, k = map(int,input().split())
su = 0
for i in range(k):
    su += 2*(w + h - 4) + 4
    w -= 4
    h -= 4
print(su)