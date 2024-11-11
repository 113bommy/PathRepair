
S = input()
T = input()

liss_pos = 1
for i in range(len(T)):
    if T[i] == S[liss_pos-1]:
        liss_pos += 1

print(liss_pos)
