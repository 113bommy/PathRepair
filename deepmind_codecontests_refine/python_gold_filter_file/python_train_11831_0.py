l = tuple(input())
sum = 0

for i in range(len(l)):
    if l[i] == 'a' or l[i] == 'i' or l[i] == 'u' or l[i] == 'e' or l[i] == 'o':
        sum += 1
    if l[i] == '1' or l[i] == '3' or l[i] == '5' or l[i] == '7' or l[i] == '9':
        sum += 1

print(sum)
