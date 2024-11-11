n = int(input())
s = str(input())
r = 0
A1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
A2 = "abcdefghijklmnopqrstuvwxyz"
T = [0 for _ in range(26)]
for i in range(0,2*n-2,2):
    T[A2.index(s[i])] += 1
    if T[A1.index(s[i+1])] == 0:
        r += 1
    else:
        T[A1.index(s[i+1])] -= 1
print(r)
