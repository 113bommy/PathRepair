n = input()
a_i = input().split(" ")
a_ii = []

for i in a_i:
    a_ii.append(int(i))
a_ii.sort()
a_ii.reverse()
mine = 0
twins = 0
j = 0
took = 0
#print((a_ii))

while j < len(a_ii):
    twins += int(a_ii[j])
    j += 1
while twins >= mine:
    mine += int(a_ii[0])
    twins -= int(a_ii[0])
    a_ii.pop(0)
    took += 1
print(took)
