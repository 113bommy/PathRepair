from sys import stdin, stdout

s = input()
count_links = 0
count_pearls = 0
for i in s:
    if i == '-':
        count_links += 1
    elif i == 'o':
        count_pearls += 1
if count_links == 0:
    print("YES")
elif count_pearls == 0:
    print("YES")
elif count_links >= count_pearls and count_links % count_pearls == 0:
    print("YES")
else:
    print("NO")

