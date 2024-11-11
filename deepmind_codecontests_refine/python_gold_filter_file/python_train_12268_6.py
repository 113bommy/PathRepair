from collections import Counter
N = int(input())
D = list(map(int, input().split()))
M = int(input())
T = list(map(int, input().split()))
Flg = "YES"

c1 = Counter(D)
c2 = Counter(T)

for i, val in c2.items():
    if(c1[i] < val):
        Flg = "NO"
        break
print(Flg)