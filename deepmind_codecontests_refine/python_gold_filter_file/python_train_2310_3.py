s = input()
n = len(s)
a = []
increase = False

x = 'Mike'
y = 'Ann'

for i in s:
    a.append(ord(i))

print(x)
lowest = a[0]

for i in range(1, n):
    if a[i] > lowest:
        print(y)
    elif a[i] <= lowest:
        print(x)
        lowest = a[i]