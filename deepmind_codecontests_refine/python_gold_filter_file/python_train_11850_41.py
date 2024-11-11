N,M = map(int, input().split())
L = []
 
for i in range(1,int(M**0.5)+1):
    if M % i == 0:
        L.append(i)
        L.append(int(M / i))
L1 = [i for i in L if M / i >= N]
print(max(L1))
