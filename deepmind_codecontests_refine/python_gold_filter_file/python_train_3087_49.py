n=int(input())
s=input()
a=s[0]
v=["a","e","i","o","u","y"]
for i in range(1,n):
    if s[i] in v and a[-1] in v:
        continue
    a+=s[i]

print(a)
