input()
ab=[chr(i) for i in range(65,91)]
s=input().upper()
n=True
for i in range(26):
    if ab[i] not in s:
        n=False
        break
if n:
    print("YES")
else:
    print("NO")