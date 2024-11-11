import sys
input = sys.stdin.readline

N = int(input())
X = input()
Xint = int(X, 2)
Xcount = X.count("1")

"""
0010
1010 10(mod2) -> 0
i = n-1の時だけ +1
0011 -> 3 -> 1->0
0110 -> 6(mod2) -> 0
"""

if Xcount == 1:
    for i in range(N):
        if X[i] == "1":
            print(0)
        elif i == N-1:
            print(2)
        else:
            print(1)
    exit()

Modplus, Modminus = Xint%(Xcount+1), Xint%(Xcount-1)

def f(x):
    if x == 0:
        return 0
    return f(x%bin(x).count("1"))+1

for i in range(N):
    if X[i] == "1":
        print(1+f((Modminus-pow(2, N-1-i, Xcount-1))%(Xcount-1)))
    else:
        print(1+f((Modplus+pow(2, N-1-i, Xcount+1))%(Xcount+1)))
