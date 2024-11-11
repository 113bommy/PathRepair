t=input()
p=input()
l_t=len(t)
l_p=len(p)
for i in range(l_t-l_p+1):
    if t[i:i+l_p]==p:print(i)