n, m = map(int, input().split())
x = 0
a = ''
for i in range(n):
        a = a + input()
if 'C' in a or 'M' in a or 'Y' in a:
    print('#Color')
else:
    print('#Black&White')