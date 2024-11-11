N = int(input())
S = input()
D = {}
for i in range(1,N):
    D[S[i-1:i+1]] = D.get(S[i-1:i+1],0) + 1
print(max([(i[1],i[0]) for i in D.items()])[1])
