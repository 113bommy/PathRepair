from collections import defaultdict
N = int(input())
dic = defaultdict(int)
for i in range(N):
    A = int(float(input())*10**9+0.1)
    two = 0
    five = 0
    while A % 2 == 0:
        A //= 2
        two += 1
    while A % 5 == 0:
        A //= 5
        five += 1
    dic[(two,five)] += 1
ans = 0
for T1,F1 in dic.keys():
    for T2,F2 in dic.keys():
        if T1+T2 >= 18 and F1+F2 >= 18:
            X = dic[(T1,F1)]
            Y = dic[(T2,F2)]
            if T1 == T2 and F1 == F2:
                ans += X*(X-1)
            else:
                ans += X*Y
print(ans//2)