prime = []
def SieveOfEratosthenes():
    n = 6000
    global prime
    prime = [True for q in range(n + 1)]
    p = 2
    while (p * p <= n):
        if (prime[p] == True):
            for i in range(p * p, n + 1, p):
                prime[i] = False
        p += 1
SieveOfEratosthenes()
I = input
n=int(I())
a=list(map(int,I().split()))
p=0
i=n*2+1
while True:
    if prime[i]==True:
        p=i
        break
    i+=1
ans=['2 '+str(n)+' 1','1 '+str(n)+' '+str(p)]
for i in range(n-1):
    ans.append('2 '+str(i+1)+' '+str(p-i))
print(n+1)
for i in ans:
    print(i)