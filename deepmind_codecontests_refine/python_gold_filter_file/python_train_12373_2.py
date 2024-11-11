from collections import Counter
n=int(input())
w=Counter(input())
for i in range(n-1):
    w &=Counter(input())
ans=""
for i,j in sorted(w.items()):
    ans +=i*j
print(ans)