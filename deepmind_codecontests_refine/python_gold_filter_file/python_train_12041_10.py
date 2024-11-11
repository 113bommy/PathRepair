s = input()
n = int(s)
output = []
if n > 5:
    output.append('1 2')
    for i in range(3, ((n+1)//2)+2):
        output.append('1 {}'.format(i))
    for i in range(((n + 1) // 2) + 2, (n + 1)):
        output.append('2 {}'.format(i))
else:
    output.append('-1')

for i in range(2, n+1):
    output.append('1 {}'.format(i))

print('\n'.join(output))