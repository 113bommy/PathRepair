a = input()
b = input()
a = a.lstrip('0')
b = b.lstrip('0')
if len(a) != len(b):
    print('<' if len(a)<len(b) else '>')
    exit(0)
for i in range(len(a)):
    if a[i] != b[i]:
        print('<' if a[i]<b[i] else '>')
        exit(0)
print('=')