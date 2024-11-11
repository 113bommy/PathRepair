k = int(input())
c = 0
while k + 1 >= 2**c:
        c += 1
holder = k + 1
if (k + 1) % 2 == 0:
    holder = k + 2
solution = [[2**(c+1)-1, holder, 1], [2**c, k + 1, 1], [2**c, 2**c + holder, holder]]
print("3 3")
for i in range(3):
    print(' '.join(map(str, solution[i])))