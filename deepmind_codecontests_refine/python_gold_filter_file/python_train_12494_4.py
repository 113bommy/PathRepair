# l = open('input.txt').readline()
l = input()

k = 0
S1, S2 = [], []
for i in range(len(l)):
    if l[i] == '\\':
        S1.append(i)
    elif l[i] == '/' and S1:
        j = S1.pop()
        a = i - j
        k += i - j

        while S2 and S2[-1][0] > j:
            a += S2.pop()[1]
        S2.append((j, a))
print(k)
print(len(S2), *(a for j, a in S2))