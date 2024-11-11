n = int(input())
a = []
prime = [True for i in range(1299829)]
p = 2
while p*p<=1299828:
    if prime[p]== True:
        for i in range(p*p,1299828,p):
            prime[i]=False
    p+=1
for i in range(2,1299828):
    if prime[i]==True:
        a.append(i)
print(*a[:n],end=" ")