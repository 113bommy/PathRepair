a = input()
b = sorted(list(map(int,list(input()))),reverse=True)
if len(b) < len(a): b = b+[0]*(len(a)-len(b))

n = ''
m = 0
c = len(b)
for x in list(a):
    if b[m] <= int(x):
        n+=x
    else: n += str(b[m]) ; m+=1
print(n)