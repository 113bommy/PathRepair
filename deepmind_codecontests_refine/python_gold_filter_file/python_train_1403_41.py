n, k = map(int, input().split())
a = list(map(int, input().split()))
b = [[None]+[i+1] for i in range(n)]
for i in range(n):
    b[i][0] = a[i]
b.sort()

pos = 0
s = 0

while (pos < n) and (s < k):
    s += b[pos][0]
    pos += 1
    

if s > k:
    pos -= 1
print(pos)
    
for i in range(pos-1):
    print(b[i][1], end = ' ')
    
if pos:
    print(b[pos-1][1])