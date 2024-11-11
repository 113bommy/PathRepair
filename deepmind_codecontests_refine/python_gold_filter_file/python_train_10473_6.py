n = input()
n = list(map(int,n.split(' ')))
t = 0
j = 0
for i in range(n[1]+1):
    s = ((n[1]-i+1)*(n[0]*i + n[1] - i)*(n[0]*i+1))//2
    if t < s:
        t = s
print(int(t))