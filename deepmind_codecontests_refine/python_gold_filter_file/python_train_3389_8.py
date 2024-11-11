n,m=map(int,input().split())
a = []
for i in range(n):
    s = list(map(str,input().split()))
    for j in range(len(s)):
        a.append(s[j])
an =""
if ('C' in a) or ('M' in a) or ('Y' in a):
    an = ("#Color")
#if ('B' in a) or ('W' in a ) or ('G' in a):
else:
    an = ("#Black&White")
print(an)