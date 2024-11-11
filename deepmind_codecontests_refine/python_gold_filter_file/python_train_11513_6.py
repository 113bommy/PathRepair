i = list(map(int, input().split()))
n = i[0]
k = i[1]
l = []
for j in range(n):
    l.append(chr(97+j%k))
 
print(''.join(l))