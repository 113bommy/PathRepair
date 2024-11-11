a=[]
while 1:
 n=input()
 if n=='0 0':break
 a.append(n)
for s in a:
 print(*sorted(map(int,s.split())))