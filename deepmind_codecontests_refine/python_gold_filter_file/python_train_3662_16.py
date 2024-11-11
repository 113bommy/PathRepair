n,I =map(int,input().split())
a = [int(w) for w in input().split()]
 
k = 8*I//n
K = 2**k
a.sort()
b = [0]
for i in range(1, n):
    if a[i-1] != a[i]:
        b.append(i)
#print(b,k)
if len(b) <= K:
    print(0)
else:
    print(n - max(b[i+K]-b[i] for i in range(len(b) - K)))