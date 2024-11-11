import sys

r = sys.stdin.readline

dic = {}
for i in range(1, 10001):
    dic[i**3] = 1

for _ in range(int(r())):
    N = int(r())
    for i in dic.keys():
        if N - i in dic:
            print("YES")
            break
        elif i >= N:
            print("NO")
            break