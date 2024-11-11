a = list(map(int,input()))
if 4 < a[0] < 9:
    a[0] = 9 - a[0]
for i in range(1,len(a)):
    if a[i] > 4:
        a[i] = 9-a[i]
for x in a:
    print(x,end='')
print()