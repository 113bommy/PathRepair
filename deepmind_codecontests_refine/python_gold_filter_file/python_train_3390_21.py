n, m = map(int, input().split())
a = []
s = 0
for i in range(n):
    a.append(input().split())
for i in range(n):
    for j in range(m):
        if a[i][j] == 'C' or a[i][j] == 'M' or a[i][j] == 'Y':
            s = 1
if s == 1:
    print('#Color')
else:
    print('#Black&White')



