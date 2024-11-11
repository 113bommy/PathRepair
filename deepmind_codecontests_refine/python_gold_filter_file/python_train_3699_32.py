#626B
n = int(input())
cards = input()
r_count = ('R', cards.count('R'))
g_count = ('G', cards.count('G'))
b_count = ('B', cards.count('B'))
r = "RGB"
a = [r_count,g_count,b_count]
a.sort(key=lambda item: item[1])
# print(a)
if a[0][1] == 0:
    if a[1][1] == 0:
        r = a[2][0]
    elif a[1][1] != a[2][1] and a[1][1] == 1:
        r = a[1][0] + a[0][0]
    elif a[1][1] == 1:
        r = a[0][0]
print(''.join(sorted(r)))
