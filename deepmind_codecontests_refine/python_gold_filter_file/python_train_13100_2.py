from collections import Counter
N = int(input())
A = Counter(map(int, input().split()))
B = [0, 0]
for i in A.keys():
    if A[i] >= 2:
        B.append(i)
    if A[i] >= 4:
        B.append(i)
B.sort()
print(B[-1]*B[-2])