s = input()
t = input()
sl = len(s)
st = len(t)
 
n = 0
if sl > st:
    n = st
else:
    n = sl
    
 
i = 0
f = 0
ans = 0
while i < n:
    if t[-1-i] != s[-1-i]:
        ans = st - i + sl - i
        f = 1 
        break
    i += 1
 
if f == 1:
    print(ans)
else:
    print(max(st,sl) - i)