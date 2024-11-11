n=int(input().split()[0])
s=set()
r=0
for _ in[0]*n:
 t=input()
 for x in s:r+=''.join(chr((66^ord(u))*(u!=v)^ord(v))for u,v in zip(x,t))in s
 s|={t}
print(r//2)