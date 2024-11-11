from collections import Counter
k=int(input())
b=Counter()
for i in range(4):
    for j in input().rstrip():
        if 48<=ord(j)<=57:
            b[int(j)]+=1
ans="YES"
for i in b:
    if b[i]>2*k:
        ans="NO"
        break
print(ans)