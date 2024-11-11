m=input().lower()
n=input().lower()
l=0
for i in range(len(m)):
    if ord(m[i])>ord(n[i]):
        l+=1
        break
    elif ord(m[i])<ord(n[i]):
        l-=1
        break
    else:
        l=0
print(l)