nc = int(input())
cl = [int(x) for x in input().split()]
fl = []
cost= 0
j = 0
for i in sorted(cl,reverse=True):
    cost += j*i + 1
    fl.append(cl.index(i)+1)
    cl[cl.index(i)]= float('inf')
    j += 1

print(cost)
print(*fl)
