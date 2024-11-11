X,Y,Z,K = map(int,input().split())
A = list(map(int,input().split()))
B = list(map(int,input().split()))
C = list(map(int,input().split()))

AB = []
ABC = []

for i in A:
    for j in B:
        AB.append(i+j)

AB.sort(reverse=True)
AB_max = AB[:K]

for j in AB_max:
    for h in C:
        ABC.append(j+h)

ABC.sort(reverse=True)

for i in range(K):
    print(ABC[i])