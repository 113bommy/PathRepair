n = int(input())
s = input()
l = list(s)
greatest = l[0]
for i in range(n-1):
    if l[i] > l[i+1]:
        l.remove(l[i])
        break
    greatest = l[i+1]
if len(l) == n:
    l.remove(greatest)
print(''.join(l))
