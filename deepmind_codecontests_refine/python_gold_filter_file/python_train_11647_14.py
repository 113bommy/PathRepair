
S = input()
N = len(S)
for i in range(N-1):
    c2 = S[i:i+2]
    c3 = S[i:i+3]
    if len(set(c2)) == 1:
        print(i+1, i+2)
        exit()
    if  i != N-2 and len(set(c3)) == 2:
        print(i+1, i+3)
        exit()

print(-1, -1)