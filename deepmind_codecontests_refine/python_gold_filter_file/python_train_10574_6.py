s = input()
n = len(s)
mas = [0] * 4
for i in range(4):
    mas[i] = [0, 0]
    
for i in range(n):
    if s[i] == "R":
        mas[0][0] += 1
        mas[0][1] = (i + 1)%4
    if s[i] == "B":
        mas[1][0] += 1
        mas[1][1] = (i + 1)%4
    if s[i] == "Y":
        mas[2][0] += 1
        mas[2][1] = (i + 1)%4
    if s[i] == "G":
        mas[3][0] += 1
        mas[3][1] = (i + 1)%4

c = n // 4
k = n % 4
for i in range(4):
    if mas[i][1] > 0 and mas[i][1] <= k:
        mas[i] = (c + 1 - mas[i][0])
    else:
        mas[i] = (c - mas[i][0])
print(*mas)