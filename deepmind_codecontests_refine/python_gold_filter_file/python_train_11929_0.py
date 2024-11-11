t = input()
t = t.split()
n = int(t[0])
c1 = int(t[1])
c2 = int(t[2])
t = input()
d = 0
for i in t:
    if(i=="1"):
        d = d+1

min = 10**1488
for i in range(1, d+1):
    t = c1*i + i*c2*(((n//i)-1)**2) + c2*(n%i)*(2*(n//i)-1)
    if t<min:
        min = t

print(min)