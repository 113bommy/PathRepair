#B問題
N,K = map(int,input().split())
A = list(map(int,input().split()))
rui = [0]

for i in range(N):
    if i == 0:
        rui.append(A[0])
    else:
        rui.append(rui[-1]+A[i])
    
bubun = []
for i in range(N):
    I = i
    for j in range(N-i):
        J = i+j+1
        bubun.append(rui[J]-rui[I])
    
bubun.sort(reverse=True)
m = 40
MAX = 0
kari = 0
while m > 0:
    kari = 2**(m-1)
    count = 0
    for b in bubun:
        if (MAX+kari)&b == MAX+kari:
            count+=1
            
    if count >= K:
        MAX+=kari
    m-=1
    
print(MAX)