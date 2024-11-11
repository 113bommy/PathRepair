a = input().strip()
b = input().strip()
lena = len(a)
lenb = len(b)
if lena>lenb:
    print(lena)
elif lenb>lena:
    print(lenb)
elif a in b:
    print(-1)
else:
    print(lena)