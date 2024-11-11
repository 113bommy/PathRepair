n = int(input())
dat = list(map(int,input().split()))
orig1 = [0] * 150010
orig2 = [0] * 150020
for i in range(n):
    orig1[dat[i]] += 1
#print(orig1[0:10])
for i in range(1, 150001):
    if i != 1 and orig2[i-1] == 0 and orig1[i] != 0:
        orig1[i] -= 1
        orig2[i-1] += 1
    if orig2[i] == 0  and orig1[i] != 0:
        orig1[i] -= 1
        orig2[i] += 1
    if orig2[i + 1] == 0 and orig1[i] != 0:
        orig1[i] -= 1
        orig2[i+1] += 1
#print(orig1[0:10])
#print(orig2[0:10])
res = 0
for i in range(1, 150010):
    if orig2[i] != 0:
        res +=1
print(res)