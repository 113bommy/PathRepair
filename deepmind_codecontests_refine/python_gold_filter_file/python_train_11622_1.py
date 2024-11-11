n=int(input())
a=set()
for i in range(n):
    s=input()
    while 'kh' in s:
        t=s.replace('kh','h')
        s=t
    t=s.replace('u','oo')
    s=t
    a.add(s)
print(len(a))