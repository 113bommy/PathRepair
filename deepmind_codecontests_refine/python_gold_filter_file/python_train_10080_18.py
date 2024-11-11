S = input()
K = int(input())
L=set()
for i in range(5):
    for j in range(len(S)-i):
        L.add((S[j:j+i+1]))
L = sorted(list(L))
print(L[K-1])